# MyRadar

## [PDF](https://intra.epitech.eu/module/2024/B-MUL-100/LYN-1-1/acti-651800/project/file/B-MUL-100_my_radar.pdf)
## [Github](https://github.com/EpitechPGEPromo2029/B-MUL-100-LYN-1-1-myradar-leonard.leroy)

## TO CODE

### MUST

- [x] The program must take exactly one parameter.
- [x] The program must accept any filepath as argument. It corresponds to the file containing the script for the simulation containing characters and integers.
- [x] The program must displayed an error message if the script is not found or incorrect. ~~
- [x] Your window must be WIDTHxHEIGHT pixels.
- [x] The window must be closed using events.
- [x] The program must display aircrafts’ hitbox and control towers’ areas.
- [x] The program must manage as many displayed entities as possible.
- [x] Aircrafts must have 20x20 square shaped hitboxes.
- [x] Aircrafts’ hitbox and sprite must be axis-aligned.
- [x] Control towers must have circled shaped control areas.

### SHOULD

- [x] The program should display and update a timer in seconds at the top-right corner of the window.
- [x] The program should stop once all aircrafts have landed on or have been destroyed.
- [x] Aircrafts should be able to take off after a given delay.
- [x] Aircrafts and control towers should be displayed using sprites.
- [x] The program should accept the “-h” option, then display the usage.
- [x] The program should be able to switch visibility of hitboxes and areas by pressing the key ‘L’.
- [x] The program should be able to switch visibility of entities’ sprites by pressing the key ‘S’.
- [x] Possible user interactions should be explicitly displayed in the usage.

### COULD

- [ ] Aircrafts’ hitbox and size could be in a 3D space.
- [ ] Aircrafts could cross any side of a screen and appear on the opposite one.
- [ ] Aircrafts’ hitbox and sprite could rotate depending on the aircrafts’ direction.
- [x] Aircrafts’ hitbox could follow the sprite boundary.
- [ ] Aircrafts’ hitbox could have different sizes.
- [ ] Control towers’ areas could cross any side of the screen and affect the opposite one.
- [x] The program could manage floating numbers coming from the script.

## Authorized functions

### from the C library

- [x] malloc
- [x] free
- [ ] stat
- [ ] memset
- [ ] rand
- [ ] srand
- [ ] time (only with srand)
- [x] (f)open
- [ ] (f)read
- [x] (f)write
- [x] (f)close
- [x] getline

### from the CSFML library

- [x] sfRenderWindow_create
- [x] sfRenderWindow_destroy
- [x] sfRenderWindow_isOpen
- [x] sfRenderWindow_close
- [x] sfRenderWindow_pollEvent
- [x] sfRenderWindow_setFramerateLimit
- [x] sfRenderWindow_clear
- [x] sfRenderWindow_drawSprite
- [ ] sfRenderWindow_draw*Shape
- [x] sfRenderWindow_drawText
- [x] sfRenderWindow_display
- [ ] sfMusic_*
- [x] sfSprite_create
- [x] sfSprite_destroy
- [x] sfSprite_setTexture
- [x] sfSprite_setPosition
- [ ] sfSprite_setRotation
- [ ] sfSprite_move
- [ ] sfSprite_rotate
- [x] sfTexture_create
- [x] sfTexture_createFromFile
- [x] sfTexture_destroy
- [ ] sfTexture_updateFromPixels
- [x] sfText_*
- [ ] sfView_*
- [ ] sfShape_* (except _getLocalBounds and _getGlobalBounds)
- [ ] sfConvexShape_* (except _getLocalBounds and _getGlobalBounds)
- [x] sfRectangleShape_* (except _getLocalBounds and _getGlobalBounds)
- [x] sfCircleShape_* (except _getLocalBounds and _getGlobalBounds)
- [ ] sfTransform_*
- [x] sfClock_*

### from the math library

- All functions

### BONUS
- [x] By pressing the G key on the keyboard, we can display the grid and see the different sections
- [x] At the end of the program, the output tells the total number of planes, the number of survivors airplanes, and the number of crashed airplanes