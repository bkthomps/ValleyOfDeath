/*
 * Provides structs which are globally used.
 */

#ifndef GLOBAL_STRUCTS_H
#define GLOBAL_STRUCTS_H

struct Counters {
    int sound;
    int bulletTime;
    int shipMove;
    int bulletMove;
    int hpTorture;
    int torture;
    int shipAction;
    int healthRegen;
    int enemyExplosion[10];
};

struct Containers {
    int pause, menu, highscore, endless, died;
    int story1a1, story1a2, story1s3, story1p3, story1a4, story1r5, story1e5;
    int story2a1, story2a2, story2a3, story2b4, story2a5, story2a6, story2e7, story2a7;
    int story3a1, story3b2, story3a3, story3a4, story3a5, story3a6, story3a7, story3a8, storyTorture;
    int story4a1, story4a2, story4a3, story4a4, story4b5, story4a6, story4a7, story4b7, story4a8;
    int story5a1, story5a2, story5a3, story5b4, story5a5, story5a6, story5b6;
    int story6a1, story6a2, story6a3, story6b3;
    int story7w1, story7l1, story7a2, story7b2;
    int unlocks, options, deleteCheckOne, deleteCheckTwo;
};

#endif /* GLOBAL_STRUCTS_H */
