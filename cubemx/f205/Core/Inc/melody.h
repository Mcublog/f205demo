/**
 * @file melody.h
 * @author Viacheslav (v.konovalo@crystals.ru)
 * @brief
 * @version 0.1
 * @date 2024-05-04
 *
 * @copyright CSI Copyright (c) 2024
 *
 */
#ifndef MELODY_H_
#define MELODY_H_

#define REST 0

#define NOTE_B0 31

#define NOTE_C1 33

#define NOTE_CS1 35

#define NOTE_D1 37

#define NOTE_DS1 39

#define NOTE_E1 41

#define NOTE_F1 44

#define NOTE_FS1 46

#define NOTE_G1 49

#define NOTE_GS1 52

#define NOTE_A1 55

#define NOTE_AS1 58

#define NOTE_B1 62

#define NOTE_C2 65

#define NOTE_CS2 69

#define NOTE_D2 73

#define NOTE_DS2 78

#define NOTE_E2 82

#define NOTE_F2 87

#define NOTE_FS2 93

#define NOTE_G2 98

#define NOTE_GS2 104

#define NOTE_A2 110

#define NOTE_AS2 117

#define NOTE_B2 123

#define NOTE_C3 131

#define NOTE_CS3 139

#define NOTE_D3 147

#define NOTE_DS3 156

#define NOTE_E3 165

#define NOTE_F3 175

#define NOTE_FS3 185

#define NOTE_G3 196

#define NOTE_GS3 208

#define NOTE_A3 220

#define NOTE_AS3 233

#define NOTE_B3 247

#define NOTE_C4 262

#define NOTE_CS4 277

#define NOTE_D4 294

#define NOTE_DS4 311

#define NOTE_E4 330

#define NOTE_F4 349

#define NOTE_FS4 370

#define NOTE_G4 392

#define NOTE_GS4 415

#define NOTE_A4 440

#define NOTE_AS4 466

#define NOTE_B4 494

#define NOTE_C5 523

#define NOTE_CS5 554

#define NOTE_D5 587

#define NOTE_DS5 622

#define NOTE_E5 659

#define NOTE_F5 698

#define NOTE_FS5 740

#define NOTE_G5 784

#define NOTE_GS5 831

#define NOTE_A5 880

#define NOTE_AS5 932

#define NOTE_B5 988

#define NOTE_C6 1047

#define NOTE_CS6 1109

#define NOTE_D6 1175

#define NOTE_DS6 1245

#define NOTE_E6 1319

#define NOTE_F6 1397

#define NOTE_FS6 1480

#define NOTE_G6 1568

#define NOTE_GS6 1661

#define NOTE_A6 1760

#define NOTE_AS6 1865

#define NOTE_B6 1976

#define NOTE_C7 2093

#define NOTE_CS7 2217

#define NOTE_D7 2349

#define NOTE_DS7 2489

#define NOTE_E7 2637

#define NOTE_F7 2794

#define NOTE_FS7 2960

#define NOTE_G7 3136

#define NOTE_GS7 3322

#define NOTE_A7 3520

#define NOTE_AS7 3729

#define NOTE_B7 3951

#define NOTE_C8 4186

#define NOTE_CS8 4435

#define NOTE_D8 4699

#define NOTE_DS8 4978

const int32_t marioMelody[] = {
    // Super Mario Bros theme
    // Score available at https://musescore.com/user/2123/scores/2145
    // Theme by Koji Kondo
    NOTE_E5,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_E5,
    8, // 1
    NOTE_G5,
    4,
    REST,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_C5,
    -4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_E4,
    -4, // 3
    NOTE_A4,
    4,
    NOTE_B4,
    4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,
    NOTE_G4,
    -8,
    NOTE_E5,
    -8,
    NOTE_G5,
    -8,
    NOTE_A5,
    4,
    NOTE_F5,
    8,
    NOTE_G5,
    8,
    REST,
    8,
    NOTE_E5,
    4,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_B4,
    -4,
    NOTE_C5,
    -4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_E4,
    -4, // repeats from 3
    NOTE_A4,
    4,
    NOTE_B4,
    4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,
    NOTE_G4,
    -8,
    NOTE_E5,
    -8,
    NOTE_G5,
    -8,
    NOTE_A5,
    4,
    NOTE_F5,
    8,
    NOTE_G5,
    8,
    REST,
    8,
    NOTE_E5,
    4,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_B4,
    -4,

    REST,
    4,
    NOTE_G5,
    8,
    NOTE_FS5,
    8,
    NOTE_F5,
    8,
    NOTE_DS5,
    4,
    NOTE_E5,
    8, // 7
    REST,
    8,
    NOTE_GS4,
    8,
    NOTE_A4,
    8,
    NOTE_C4,
    8,
    REST,
    8,
    NOTE_A4,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    REST,
    4,
    NOTE_DS5,
    4,
    REST,
    8,
    NOTE_D5,
    -4,
    NOTE_C5,
    2,
    REST,
    2,

    REST,
    4,
    NOTE_G5,
    8,
    NOTE_FS5,
    8,
    NOTE_F5,
    8,
    NOTE_DS5,
    4,
    NOTE_E5,
    8, // repeats from 7
    REST,
    8,
    NOTE_GS4,
    8,
    NOTE_A4,
    8,
    NOTE_C4,
    8,
    REST,
    8,
    NOTE_A4,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    REST,
    4,
    NOTE_DS5,
    4,
    REST,
    8,
    NOTE_D5,
    -4,
    NOTE_C5,
    2,
    REST,
    2,

    NOTE_C5,
    8,
    NOTE_C5,
    4,
    NOTE_C5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    4, // 11
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2,

    NOTE_C5,
    8,
    NOTE_C5,
    4,
    NOTE_C5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_E5,
    8, // 13
    REST,
    1,
    NOTE_C5,
    8,
    NOTE_C5,
    4,
    NOTE_C5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    4,
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2,
    NOTE_E5,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_E5,
    4,
    NOTE_G5,
    4,
    REST,
    4,
    NOTE_G4,
    4,
    REST,
    4,
    NOTE_C5,
    -4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_E4,
    -4, // 19

    NOTE_A4,
    4,
    NOTE_B4,
    4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,
    NOTE_G4,
    -8,
    NOTE_E5,
    -8,
    NOTE_G5,
    -8,
    NOTE_A5,
    4,
    NOTE_F5,
    8,
    NOTE_G5,
    8,
    REST,
    8,
    NOTE_E5,
    4,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_B4,
    -4,

    NOTE_C5,
    -4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_E4,
    -4, // repeats from 19
    NOTE_A4,
    4,
    NOTE_B4,
    4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,
    NOTE_G4,
    -8,
    NOTE_E5,
    -8,
    NOTE_G5,
    -8,
    NOTE_A5,
    4,
    NOTE_F5,
    8,
    NOTE_G5,
    8,
    REST,
    8,
    NOTE_E5,
    4,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_B4,
    -4,

    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4, // 23
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_D5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_G5,
    -8,
    NOTE_F5,
    -8,

    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2, // 26
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4,
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_B4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_F5,
    -8,
    NOTE_E5,
    -8,
    NOTE_D5,
    -8,
    NOTE_C5,
    8,
    NOTE_E4,
    4,
    NOTE_E4,
    8,
    NOTE_C4,
    2,

    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4, // repeats from 23
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_D5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_G5,
    -8,
    NOTE_F5,
    -8,

    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2, // 26
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4,
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_B4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_F5,
    -8,
    NOTE_E5,
    -8,
    NOTE_D5,
    -8,
    NOTE_C5,
    8,
    NOTE_E4,
    4,
    NOTE_E4,
    8,
    NOTE_C4,
    2,
    NOTE_C5,
    8,
    NOTE_C5,
    4,
    NOTE_C5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    8,
    NOTE_E5,
    8,
    REST,
    1,

    NOTE_C5,
    8,
    NOTE_C5,
    4,
    NOTE_C5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_D5,
    4, // 33
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2,
    NOTE_E5,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_E5,
    8,
    REST,
    8,
    NOTE_C5,
    8,
    NOTE_E5,
    4,
    NOTE_G5,
    4,
    REST,
    4,
    NOTE_G4,
    4,
    REST,
    4,
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4,
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_D5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_A5,
    -8,
    NOTE_G5,
    -8,
    NOTE_F5,
    -8,

    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_A4,
    8,
    NOTE_G4,
    2, // 40
    NOTE_E5,
    8,
    NOTE_C5,
    4,
    NOTE_G4,
    8,
    REST,
    4,
    NOTE_GS4,
    4,
    NOTE_A4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_A4,
    2,
    NOTE_B4,
    8,
    NOTE_F5,
    4,
    NOTE_F5,
    8,
    NOTE_F5,
    -8,
    NOTE_E5,
    -8,
    NOTE_D5,
    -8,
    NOTE_C5,
    8,
    NOTE_E4,
    4,
    NOTE_E4,
    8,
    NOTE_C4,
    2,

    // game over sound
    NOTE_C5,
    -4,
    NOTE_G4,
    -4,
    NOTE_E4,
    4, // 45
    NOTE_A4,
    -8,
    NOTE_B4,
    -8,
    NOTE_A4,
    -8,
    NOTE_GS4,
    -8,
    NOTE_AS4,
    -8,
    NOTE_GS4,
    -8,
    NOTE_G4,
    8,
    NOTE_D4,
    8,
    NOTE_E4,
    -2,
};

const int32_t melody_StarWarsTheme[] = {
    // Dart Vader theme (Imperial March) - Star wars
    // Score available at https://musescore.com/user/202909/scores/1141521
    // The tenor saxophone part was used
    NOTE_AS4, 8,  NOTE_AS4, 8,  NOTE_AS4, 8, // 1
    NOTE_F5,  2,  NOTE_C6,  2,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,
    NOTE_F6,  2,  NOTE_C6,  4,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,
    NOTE_F6,  2,  NOTE_C6,  4,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_AS5, 8,
    NOTE_G5,  2,  NOTE_C5,  8,  NOTE_C5,  8,  NOTE_C5,  8,  NOTE_F5,  2,
    NOTE_C6,  2,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,  NOTE_F6,  2,
    NOTE_C6,  4,

    NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,  NOTE_F6,  2,  NOTE_C6,  4, // 8
    NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_AS5, 8,  NOTE_G5,  2,  NOTE_C5,  -8,
    NOTE_C5,  16, NOTE_D5,  -4, NOTE_D5,  8,  NOTE_AS5, 8,  NOTE_A5,  8,
    NOTE_G5,  8,  NOTE_F5,  8,  NOTE_F5,  8,  NOTE_G5,  8,  NOTE_A5,  8,
    NOTE_G5,  4,  NOTE_D5,  8,  NOTE_E5,  4,  NOTE_C5,  -8, NOTE_C5,  16,
    NOTE_D5,  -4, NOTE_D5,  8,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,
    NOTE_F5,  8,

    NOTE_C6,  -8, NOTE_G5,  16, NOTE_G5,  2,  REST,     8,  NOTE_C5,  8, // 13
    NOTE_D5,  -4, NOTE_D5,  8,  NOTE_AS5, 8,  NOTE_A5,  8,  NOTE_G5,  8,
    NOTE_F5,  8,  NOTE_F5,  8,  NOTE_G5,  8,  NOTE_A5,  8,  NOTE_G5,  4,
    NOTE_D5,  8,  NOTE_E5,  4,  NOTE_C6,  -8, NOTE_C6,  16, NOTE_F6,  4,
    NOTE_DS6, 8,  NOTE_CS6, 4,  NOTE_C6,  8,  NOTE_AS5, 4,  NOTE_GS5, 8,
    NOTE_G5,  4,  NOTE_F5,  8,  NOTE_C6,  1};

const int32_t melody_NokiaTune[] = {
    // Nokia Ringtone
    // Score available at https://musescore.com/user/29944637/scores/5266155
    NOTE_E5,  8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_CS5, 8,
    NOTE_B4,  8, NOTE_D4, 4, NOTE_E4,  4, NOTE_B4,  8, NOTE_A4,  8,
    NOTE_CS4, 4, NOTE_E4, 4, NOTE_A4,  2,
};

const int32_t melody_CannonInD[] = {
    // Cannon in D - Pachelbel
    // Score available at https://musescore.com/user/4710311/scores/1975521
    // C F
    NOTE_FS4, 2, NOTE_E4,  2, NOTE_D4,  2, NOTE_CS4, 2, NOTE_B3,  2,
    NOTE_A3,  2, NOTE_B3,  2, NOTE_CS4, 2, NOTE_FS4, 2, NOTE_E4,  2,
    NOTE_D4,  2, NOTE_CS4, 2, NOTE_B3,  2, NOTE_A3,  2, NOTE_B3,  2,
    NOTE_CS4, 2, NOTE_D4,  2, NOTE_CS4, 2, NOTE_B3,  2, NOTE_A3,  2,
    NOTE_G3,  2, NOTE_FS3, 2, NOTE_G3,  2, NOTE_A3,  2,

    NOTE_D4,  4, NOTE_FS4, 8, NOTE_G4,  8, NOTE_A4,  4, NOTE_FS4, 8,
    NOTE_G4,  8, NOTE_A4,  4, NOTE_B3,  8, NOTE_CS4, 8, NOTE_D4,  8,
    NOTE_E4,  8, NOTE_FS4, 8, NOTE_G4,  8, NOTE_FS4, 4, NOTE_D4,  8,
    NOTE_E4,  8, NOTE_FS4, 4, NOTE_FS3, 8, NOTE_G3,  8, NOTE_A3,  8,
    NOTE_G3,  8, NOTE_FS3, 8, NOTE_G3,  8, NOTE_A3,  2, NOTE_G3,  4,
    NOTE_B3,  8, NOTE_A3,  8, NOTE_G3,  4, NOTE_FS3, 8, NOTE_E3,  8,
    NOTE_FS3, 4, NOTE_D3,  8, NOTE_E3,  8, NOTE_FS3, 8, NOTE_G3,  8,
    NOTE_A3,  8, NOTE_B3,  8,

    NOTE_G3,  4, NOTE_B3,  8, NOTE_A3,  8, NOTE_B3,  4, NOTE_CS4, 8,
    NOTE_D4,  8, NOTE_A3,  8, NOTE_B3,  8, NOTE_CS4, 8, NOTE_D4,  8,
    NOTE_E4,  8, NOTE_FS4, 8, NOTE_G4,  8, NOTE_A4,  2, NOTE_A4,  4,
    NOTE_FS4, 8, NOTE_G4,  8, NOTE_A4,  4, NOTE_FS4, 8, NOTE_G4,  8,
    NOTE_A4,  8, NOTE_A3,  8, NOTE_B3,  8, NOTE_CS4, 8, NOTE_D4,  8,
    NOTE_E4,  8, NOTE_FS4, 8, NOTE_G4,  8, NOTE_FS4, 4, NOTE_D4,  8,
    NOTE_E4,  8, NOTE_FS4, 8, NOTE_CS4, 8, NOTE_A3,  8, NOTE_A3,  8,

    NOTE_CS4, 4, NOTE_B3,  4, NOTE_D4,  8, NOTE_CS4, 8, NOTE_B3,  4,
    NOTE_A3,  8, NOTE_G3,  8, NOTE_A3,  4, NOTE_D3,  8, NOTE_E3,  8,
    NOTE_FS3, 8, NOTE_G3,  8, NOTE_A3,  8, NOTE_B3,  4, NOTE_G3,  4,
    NOTE_B3,  8, NOTE_A3,  8, NOTE_B3,  4, NOTE_CS4, 8, NOTE_D4,  8,
    NOTE_A3,  8, NOTE_B3,  8, NOTE_CS4, 8, NOTE_D4,  8, NOTE_E4,  8,
    NOTE_FS4, 8, NOTE_G4,  8, NOTE_A4,  2,
};

const int32_t melody_gotchi_fault[] = {
    // Never Gonna Give You Up - Rick Astley
    // Score available at
    // https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
    // Arranged by Chlorondria
    NOTE_A4,  16, NOTE_B4,  16, NOTE_D5,  16, NOTE_B4,  16,

    NOTE_FS5, -8, NOTE_FS5, -8, NOTE_E5,  -4, NOTE_A4,  16, NOTE_B4, 16,
    NOTE_D5,  16, NOTE_B4,  16, NOTE_E5,  -8, NOTE_E5,  -8, NOTE_D5, -8,
    NOTE_CS5, 16, NOTE_B4,  8,  NOTE_A4,  16, NOTE_B4,  16, NOTE_D5, 16,
    NOTE_B4,  16, NOTE_D5,  4,  NOTE_E5,  8,  NOTE_CS5, -8, NOTE_B4, 16,
    NOTE_A4,  4,  NOTE_A4,  8,

    NOTE_E5,  4,  NOTE_D5,  2,  NOTE_A4,  16, NOTE_B4,  16, NOTE_D5, 16,
    NOTE_B4,  16, // 40
    NOTE_FS5, -8, NOTE_FS5, -8, NOTE_E5,  -4, NOTE_A4,  16, NOTE_B4, 16,
    NOTE_D5,  16, NOTE_B4,  16, NOTE_A5,  4,  NOTE_CS5, 8,  NOTE_D5, -8,
    NOTE_CS5, 16, NOTE_B4,  8,  NOTE_A4,  16, NOTE_B4,  16, NOTE_D5, 16,
    NOTE_B4,  16, NOTE_D5,  4,  NOTE_E5,  8,  NOTE_CS5, -8, NOTE_B4, 16,
    NOTE_A4,  4,  NOTE_A4,  8,  NOTE_E5,  4,  NOTE_D5,  2,  NOTE_A4, 16,
    NOTE_B4,  16, NOTE_D5,  16, NOTE_B4,  16,

    NOTE_FS5, -8, NOTE_FS5, -8, NOTE_E5,  -4, NOTE_A4,  16, NOTE_B4, 16,
    NOTE_D5,  16, NOTE_B4,  16, // 45
    NOTE_A5,  4,  NOTE_CS5, 8,  NOTE_D5,  -8, NOTE_CS5, 16, NOTE_B4, 8,
    NOTE_A4,  16, NOTE_B4,  16, NOTE_D5,  16, NOTE_B4,  16, NOTE_D5, 4,
    NOTE_E5,  8,  NOTE_CS5, -8, NOTE_B4,  16, NOTE_A4,  4,  NOTE_A4, 8,
    NOTE_E5,  4,  NOTE_D5,  2,  NOTE_A4,  16, NOTE_B4,  16, NOTE_D5, 16,
    NOTE_B4,  16, NOTE_FS5, -8, NOTE_FS5, -8, NOTE_E5,  -4, NOTE_A4, 16,
    NOTE_B4,  16, NOTE_D5,  16, NOTE_B4,  16, // 45

    NOTE_A5,  4,  NOTE_CS5, 8,  NOTE_D5,  -8, NOTE_CS5, 16, NOTE_B4, 8,
    NOTE_A4,  16, NOTE_B4,  16, NOTE_D5,  16, NOTE_B4,  16, NOTE_D5, 4,
    NOTE_E5,  8,  NOTE_CS5, -8, NOTE_B4,  16, NOTE_A4,  4,  NOTE_A4, 8,

    NOTE_E5,  4,  NOTE_D5,  2,  REST,     4};

const int32_t *melody[] = {marioMelody, melody_StarWarsTheme, melody_NokiaTune,
                            melody_CannonInD, melody_gotchi_fault};

const uint32_t melodySizes[] = {sizeof(marioMelody) / sizeof(int32_t),
                                sizeof(melody_StarWarsTheme) / sizeof(int32_t),
                                sizeof(melody_NokiaTune) / sizeof(int32_t),
                                sizeof(melody_CannonInD) / sizeof(int32_t),
                                sizeof(melody_gotchi_fault) / sizeof(int32_t)};
#endif /* MELODY_H_ */
