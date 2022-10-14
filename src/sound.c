/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sound.c
*/

#include "my_rpg.h"

sfSound *create_sound(char *filepath)
{
    sfSoundBuffer *buff =
                    sfSoundBuffer_createFromFile(filepath);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff);
    return sound;
}

sfMusic *create_game_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, MUSIC_VOLUME);
    return music;
}
