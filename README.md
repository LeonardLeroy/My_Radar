# My_Radar (MyRadar)

A 2D air-traffic simulation panel written in C using **CSFML**. The program reads a *script file* describing aircraft and control towers, then runs a real-time simulation in a **1950×1080** window with optional overlays (hitboxes, control areas, grid, chronometer).

> Project binary name: `my_radar` (see `Makefile`)

---

## Features

- Real-time simulation with CSFML rendering (sprites + optional debug shapes)
- Loads entities from a script file:
  - **Aircraft** with departure, arrival, speed, and takeoff delay
  - **Control towers** with a circular control area (radius)
- Collision detection between aircraft (optimized using a grid/section partitioning)
- Runtime toggles:
  - show/hide hitboxes & tower areas
  - show/hide sprites
  - show/hide grid sections
  - show/hide chronometer (timer)
- End-of-simulation summary printed to stdout:
  - total aircraft
  - survived aircraft
  - crashed aircraft

---

## Requirements

### Build dependencies
- GCC (or compatible C compiler)
- CSFML:
  - `csfml-graphics`
  - `csfml-window`
  - `csfml-system`
- `libm` (math library)

On many Linux systems you can install CSFML via your package manager (package names vary).

### Runtime assets
The program expects these files to exist:
- `assets/worldmap.png` (background)
- `assets/aircraft.png` (aircraft sprite)
- `assets/tower.png` (tower sprite)
- `assets/fast.ttf` (font for the chronometer)

---

## Build

```sh
make
```

This produces the executable:

```sh
./my_radar
```

### Clean targets

```sh
make clean
make fclean
make re
```

### Unit tests (optional)
The Makefile includes a Criterion-based test target:

```sh
make tests_run
```

(Requires Criterion and coverage tooling like `gcovr` to be installed.)

---

## Usage

### Run the simulation

```sh
./my_radar path_to_script
```

- The program **must** receive **exactly one argument** (the script path).
- If the script file cannot be opened or is invalid, the program exits with code **84** and prints an error message to stderr.

### Help

```sh
./my_radar -h
```

Prints usage and exits successfully.

---

## Keyboard controls (in simulation)

| Key | Action |
|-----|--------|
| `L` | Toggle aircraft hitboxes and tower control areas |
| `S` | Toggle entity sprites |
| `G` | Toggle grid sections (spatial partition visualization) |
| `C` | Toggle chronometer display |
| Window close | Close the simulation window |

Notes:
- The chronometer is displayed only when enabled (`C`). It appears near the top-right of the window.

---

## Script format

The script is a text file read line-by-line. Each line defines either:
- an **Aircraft** (line starts with `A`)
- a **Tower** (line starts with `T`)

### Aircraft line

```
A x_depart y_depart x_arrivee y_arrivee speed delay
```

- `x_depart y_depart`: departure coordinates (float supported)
- `x_arrivee y_arrivee`: arrival coordinates (float supported)
- `speed`: movement speed (float supported)
- `delay`: takeoff delay in seconds (float supported)

### Tower line

```
T x_position y_position radius
```

- `x_position y_position`: tower center coordinates (float supported)
- `radius`: control area radius (float supported)

### Example

```
T 500 300 120
A 100 100 800 600 2.5 1
A 120 140 850 620 2.5 3
```

Implementation note: the loader counts aircraft/tower lines first, allocates arrays accordingly, then parses aircraft first and towers afterward. For best results, keep the script consistent and well-formed.

---

## Simulation behavior

### Window and rendering
- Window size: **1950×1080**
- Title: `"My Airline Trafic Simulator"`
- Background: `assets/worldmap.png` (drawn every frame if loaded)
- Frame rate capped to 60 FPS

### Takeoff delay
Each aircraft has its own clock. Collision checks ignore aircraft that:
- haven’t reached their `delay` time yet, or
- already have `speed == 0` (stopped)

### When does the simulation stop?
The main loop ends when **no aircraft has a speed greater than 0** (i.e., all have effectively stopped moving). At that point the window closes/breaks and results are printed.

---

## Collision & control tower rules (implementation notes)

### Spatial partitioning (grid sections)
To reduce collision checks, the airspace is partitioned into a grid:

- Section size: `50`
- Grid rows: `HEIGHT / SECTION_SIZE`
- Grid cols: `WIDTH / SECTION_SIZE`

Each frame:
1. The program creates a grid of sections.
2. Each aircraft is updated and inserted into its current section.
3. Collisions are checked **within each section** (pairwise among aircraft in the same cell).
4. The section grid is freed.

### Aircraft collision detection
Aircraft are considered intersecting if the distance between their hitbox positions is:

- `<= 20 + COLLISION_TOLERANCE`

### Control tower protection rule
If **both** aircraft involved in a potential collision are inside **any** control tower area, the collision is ignored (aircraft are considered “protected” when under tower coverage).

- A point is “in a control area” if its distance to the tower center is `<= radius`.

### What happens on collision?
When a collision is confirmed:
- both aircraft speeds are set to `0`
- their hitbox outline is set to **red**
- the sprite is made transparent (visually “removed”)

---

## Exit codes & errors

- `0`: success
- `84`: error (invalid args, missing file, texture/window/background/entity allocation issues, etc.)

Common stderr messages include:
- `Error file`
- `Error texture`
- `Error window`
- `Error background`
- `Error aircraft`
- `Error tower`
- `Error section`

---

## Repository layout

- `src/`: simulation, parsing, rendering, collision detection
- `include/`: public header(s) (`my_radar.h`)
- `assets/`: textures/font used at runtime
- `lib/my/`: custom utility library used by the project (string/number helpers, output)

---

## Notes / known implementation details

- Numeric parsing supports floating values using a custom conversion (`my_atof_combined`) based on integer parsing + decimal extraction.
- The background texture is created in `create_background_sprite()`; if it fails, the program reports a background error.
- The chronometer font is loaded from disk when drawing the chronometer; ensure `assets/fast.ttf` is available.
- The simulation result counts “crashed” vs “survived” using the **outline color** of the aircraft hitbox:
  - red outline → crashed
  - green outline → survived  
  (So to see accurate “survived” counts, ensure aircraft that successfully complete their flight are marked accordingly by the update/landing logic.)