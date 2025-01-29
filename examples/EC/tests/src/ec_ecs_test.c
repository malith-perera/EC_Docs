#include "ec_ecs_test.h"


/* Components */
EC_Component_C(Velocity)
EC_Component_C(Position)
EC_Component_C(Score)
EC_Component_C(ActionVelocity)

/* Player */
EC_Entity_C(Player)
EC_Entity_Component_C(Player, Velocity)
EC_Entity_Component_C(Player, Position)
EC_Entity_Component_C(Player, Score)
EC_Entity_Component_C(Player, ActionVelocity)

/* Enemy */
EC_Entity_C(Enemy)
EC_Entity_Component_C(Enemy, Velocity)
EC_Entity_Component_C(Enemy, Position)

void
Test_ECS_Component_Arrays()
{
    //assert(n_velocity == 5);
    EC_Test_Print_Msg("Check n_velocity", "OK", __LINE__);
}

void
Test_ECS_Entity_Assign()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: ec[Entity]_Assign functions");

    Player_Assign(1, 2);
    Enemy_Assign(3, 5);

    // Check ecPlayerEntity
    assert(ecPlayerEntity.n == 1);
    assert(ecPlayerEntity.m == 2);
    EC_Test_Print_Msg("Check ecPlayerEntity", "OK", __LINE__);

    // Check ecEnemyEntity
    assert(ecEnemyEntity.n == 3);
    assert(ecEnemyEntity.m == 5);
    EC_Test_Print_Msg("Check ecEnemyEntity", "OK", __LINE__);
}

void
Test_ECS_Entity_Component_Assign()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: [Entity]_[Component]_Assign functions");

    Player_Velocity_Assign();
    Player_Position_Assign();
    Player_Score_Assign();
    Player_ActionVelocity_Assign();

    // Check ecPlayerVelocity
    assert(ecPlayerVelocity->n == 1);
    assert(ecPlayerVelocity->m == 2);
    EC_Test_Print_Msg("Check ecPlayerVelocity", "OK", __LINE__);

    // Check Player EntityComponentList
    assert(ecPlayerEntityComponentList->entity_component->n == 1);
    assert(ecPlayerEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecPlayerEntityComponentList", "OK", __LINE__);

    // Check Velocity EntityComponentList
    assert(ecVelocityEntityComponentList->entity_component->n == 1);
    assert(ecVelocityEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecVelocityEntityComponentList", "OK", __LINE__);

    // Check Position EntityComponentList
    assert(ecPositionEntityComponentList->entity_component->n == 1);
    assert(ecPositionEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecPositionEntityComponentList", "OK", __LINE__);

    // Check Score EntityComponentList
    assert(ecScoreEntityComponentList->entity_component->n == 1);
    assert(ecScoreEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecScoreEntityComponentList", "OK", __LINE__);

    // Check AcitonVelocity EntityComponentList
    assert(ecActionVelocityEntityComponentList->entity_component->n == 1);
    assert(ecActionVelocityEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecActionVelocityEntityComponentList", "OK", __LINE__);

    Enemy_Velocity_Assign();
    Enemy_Position_Assign();

    // Check ecEnemyVelocity
    assert(ecEnemyVelocity->n == 3);
    assert(ecEnemyVelocity->m == 5);
    EC_Test_Print_Msg("Check ecEnemyVelocity", "OK", __LINE__);

    // Check ecEnemyVelocityList
    assert(ecVelocityEntityComponentList->entity_component->n == 3);
    assert(ecVelocityEntityComponentList->entity_component->m == 5);
    EC_Test_Print_Msg("Check ecVelocityEntityComponentList", "OK", __LINE__);

    // check entity component list next
    assert(ecVelocityEntityComponentList->next->entity_component->n == 1);
    assert(ecVelocityEntityComponentList->next->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecVelocityEntityComponentList next", "OK", __LINE__);
 
    // check entity component list last next
    assert(ecVelocityEntityComponentList->next->next == NULL);
    EC_Test_Print_Msg("Check ecVelocityEntityComponentList last next", "OK", __LINE__);

    // Check ecPlayerScore
    assert(ecPlayerScore->n == 1);
    assert(ecPlayerScore->m == 2);
    EC_Test_Print_Msg("Check ecPlayerScore", "OK", __LINE__);

    // Check ecPlayerScoreList
    assert(ecScoreEntityComponentList->entity_component->n == 1);
    assert(ecScoreEntityComponentList->entity_component->m == 2);
    EC_Test_Print_Msg("Check ecVelocityEntityComponentList", "OK", __LINE__);

    // check entity component list last next
    assert(ecScoreEntityComponentList->next == NULL);
    EC_Test_Print_Msg("Check ecScoreEntityComponentList last next", "OK", __LINE__);
}

void
Test_ECS_Component_Assign()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: [Component]_Assign functions");

    Velocity_Assign(); 
    Position_Assign(); 
    ActionVelocity_Assign(); 

    // velocity array shoud have 8 elements 
    assert(sizeof(ecVelocity) == 8);
    EC_Test_Print_Msg("Check ecVelocity size", "OK", __LINE__);

    // velocity array shoud have 8 elements 
    assert(sizeof(ecPosition) == 8);
    EC_Test_Print_Msg("Check ecPosition size", "OK", __LINE__);

    // velocity array shoud have 8 elements 
    assert(sizeof(ecActionVelocity) == 8);
    EC_Test_Print_Msg("Check ecActionVelocity size", "OK", __LINE__);
}

void
Test_ECS_Entity_Component_Init()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: Entity Component Init");

    Player_Velocity(0)->x = 1;
    Player_Velocity(0)->y = 2;
    Player_Position(0)->x = 3;
    Player_Position(0)->y = 4;
    Player_ActionVelocity(0)->x = 5;
    Player_ActionVelocity(0)->y = 6;

    Player_Velocity(1)->x = 11;
    Player_Velocity(1)->y = 12;
    Player_Position(1)->x = 13;
    Player_Position(1)->y = 14;
    Player_ActionVelocity(1)->x = 15;
    Player_ActionVelocity(1)->y = 16;

    Enemy_Velocity(0)->x = 1;
    Enemy_Velocity(0)->y = 2;
    Enemy_Position(0)->x = 3;
    Enemy_Position(0)->y = 4;

    Enemy_Velocity(1)->x = 11;
    Enemy_Velocity(1)->y = 12;
    Enemy_Position(1)->x = 13;
    Enemy_Position(1)->y = 14;

    Enemy_Velocity(2)->x = 21;
    Enemy_Velocity(2)->y = 22;
    Enemy_Position(2)->x = 23;
    Enemy_Position(2)->y = 24;

    Enemy_Velocity(3)->x = 31;
    Enemy_Velocity(3)->y = 32;
    Enemy_Position(3)->x = 33;
    Enemy_Position(3)->y = 34;

    Enemy_Velocity(4)->x = 41;
    Enemy_Velocity(4)->y = 42;
    Enemy_Position(4)->x = 43;
    Enemy_Position(4)->y = 44;

    assert(Player_Velocity(0)->x == 1);
    assert(Player_Velocity(0)->y == 2);
    assert(Player_Position(0)->x == 3);
    assert(Player_Position(0)->y == 4);
    assert(Player_ActionVelocity(0)->x == 5);
    assert(Player_ActionVelocity(0)->y == 6);

    assert(Player_Velocity(1)->x == 11);
    assert(Player_Velocity(1)->y == 12);
    assert(Player_Position(1)->x == 13);
    assert(Player_Position(1)->y == 14);
    assert(Player_ActionVelocity(1)->x == 15);
    assert(Player_ActionVelocity(1)->y == 16);

    assert(Enemy_Velocity(0)->x == 1);
    assert(Enemy_Velocity(0)->y == 2);
    assert(Enemy_Position(0)->x == 3);
    assert(Enemy_Position(0)->y == 4);

    assert(Enemy_Velocity(1)->x == 11);
    assert(Enemy_Velocity(1)->y == 12);
    assert(Enemy_Position(1)->x == 13);
    assert(Enemy_Position(1)->y == 14);

    assert(Enemy_Velocity(2)->x == 21);
    assert(Enemy_Velocity(2)->y == 22);
    assert(Enemy_Position(2)->x == 23);
    assert(Enemy_Position(2)->y == 24);

    assert(Enemy_Velocity(3)->x == 31);
    assert(Enemy_Velocity(3)->y == 32);
    assert(Enemy_Position(3)->x == 33);
    assert(Enemy_Position(3)->y == 34);

    assert(Enemy_Velocity(4)->x == 41);
    assert(Enemy_Velocity(4)->y == 42);
    assert(Enemy_Position(4)->x == 43);
    assert(Enemy_Position(4)->y == 44);

    EC_Test_Print_Msg("Entity Component Init", "OK", __LINE__);
}

void
Test_ECS_for_entity()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: for_entity");

    for_entity(Player, player) {
        assert(Player_Velocity(player)->x == 1);
        assert(Player_Velocity(player)->y == 2);
    }

    EC_Test_Print_Msg("Check for_entity for Player", "OK", __LINE__);

    Velocity enemy_velocity[4] = {1, 2, 11,12, 21, 22};

    for_entity(Enemy, enemy) {
        assert(Enemy_Velocity(enemy)->x == enemy_velocity[enemy].x);
        assert(Enemy_Velocity(enemy)->y == enemy_velocity[enemy].y);
    }

    EC_Test_Print_Msg("Check for_entity for Enemy", "OK", __LINE__);

    EC_Test_Print_Msg("for_entity", "OK", __LINE__);
}

void
Test_ECS_Get_Component()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: Get_Component macro");

    assert(Player(0, Velocity).x == 1);
    assert(Player(0, Velocity).y == 2);
    assert(Player(1, Velocity).x == 11);
    assert(Player(1, Velocity).y == 12);

    EC_Test_Print_Msg("Player(0, Velocity)", "OK", __LINE__);

    assert(Enemy(0, Position).x == 3);
    assert(Enemy(0, Position).y == 4);
    assert(Enemy(1, Position).x == 13);
    assert(Enemy(1, Position).y == 14);

    EC_Test_Print_Msg("Enemy(0, Position)", "OK", __LINE__);

    EC_Test_Print_Msg("Get_Component macro", "OK", __LINE__);
}

void
Test_ECS_Free()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: Free functions");

    // Check [Entity]_Free functions
    Player_Free();
    Enemy_Free();
    EC_Test_Print_Msg("[Entity]_Free", "OK", __LINE__);

    // Check [Component]_Free functions 
    Velocity_Free();
    Position_Free();
    Score_Free();
    ActionVelocity_Free();
    EC_Test_Print_Msg("[Component]_Free", "OK", __LINE__);

    EC_Test_Print_Msg("Free functions", "OK", __LINE__);
}

void
Run_ECS_Test()
{
    printf("------------\n");
    printf("Test: ec_ecs\n");
    printf("============\n");

    Test_ECS_Entity_Assign();
    printf("\n");

    Test_ECS_Entity_Component_Assign();
    printf("\n");

    Test_ECS_Component_Assign();
    printf("\n");

    Test_ECS_Entity_Component_Init();
    printf("\n");

    Test_ECS_for_entity();
    printf("\n");

    Test_ECS_Get_Component();
    printf("\n");

    Test_ECS_Free();
    printf("\n");

    EC_Test_Print_Msg("Test: ec_ecs.h", "PASS", __LINE__);
    printf("\n");
}
