#include "ec_ecs.h"


/* new ecs */

int ec_n_entity; // total number of entities
EC_EntityComponentList *ec_entity_component_list = NULL; // All entity components



/* end new ecs */


int nEntity;


ECEntity
EC_Entity_New (int n, int M)
{
    ECEntity entity;
    entity.I = nEntity;           // first entity id
    entity.n = nEntity + n;       // currunt number of entities exist after some time
    entity.M = M;                 // maximum number of entities required for an entity type in an array
    nEntity += M;                 // increase total number of entities

    return entity;
}


void
ECS_Free ()
{
    //Entity_Request_Array_Free ();
    //Entity_List_Free ();
}































#if 0

static int entity_i;


int
Entity_Get ()
{
    return entity_i;
}


Entity *
Entity_Request2 (Entity *type, int n, int m)
{
    Entity *entity_request = (Entity *) malloc (sizeof (Entity)) ;
    entity_request->n = n;
    entity_request->m = m;
    entity_request->component = NULL;
    entity_request->next = NULL;

    if (request_list == NULL)
    {
        request_list = entity_request;
    }
    else
    {
        Entity *request_temp = request_list; 
        request_list = entity_request;
        request_list->next = request_temp;
    }

    return entity_request;
}


void
Entity_Reset(Entity *entity, int n, int m)
{
    Entity *entity_request = NULL;
    
    // check whether entity requsted again before complete the request 
    #ifdef EC_WARN
        bool request_exist = false;

        for (int mode_i = 0; mode_i < N_ENTITY_REQUEST_MODE; mode_i++)
        {
            Entity *requested_entities = entity_request_array[mode_i];

            while (requested_entities != NULL)
            {

                entity_request = requested_entities;
                EC_Warn_Print_Msg("Warning : ", "Request same entity twice before request complete. Final entity request used.", __LINE__);
                request_exist = true;
                goto exit_loop;

            requested_entities = requested_entities->next;
            }
        }

        entity_request = (Entity *) malloc (sizeof (Entity)) ;
        entity_request->next = NULL;

        exit_loop:
        entity_request->n = n;
        entity_request->m = m;
    #else
        entity_request = (Entity *) malloc (sizeof (Entity)) ;
        entity_request->n = n;
        entity_request->m = m;
        entity_request->next = NULL;
    #endif

    EntityRequestMode mode;

    if (entity == NULL)
    {
        mode = ENTITY_NEW;
    }
    else
    {
        if (m == 0)
        {
             mode = ENTITY_DROP; // drop but do not delete
        }
        else if (m < 0)
        {
             mode = ENTITY_DELETE; // delete entity
        }
        else
        {
            Entity *current_entity = entity;
            int entity_total = 0;

            while (current_entity != NULL)
            {
                entity_total += current_entity->m;
            }

            if (m > entity_total)
            {
                mode = ENTITY_INCRESE; // less than existing entities
            }
            else
            {
                mode = ENTITY_DECRESE; // more than existing entities
            }
        }
    }

    #ifdef EC_WARN
        if (request_exist == false)
        {
            if (entity_request_array[mode] == NULL)
            {
                entity_request_array[mode] = entity_request;
            }
            else
            {
                Entity *request_temp = entity_request_array[mode]; 
                entity_request_array[mode] = entity_request;
                entity_request->next = request_temp;
            }
        }
    #else
        if (entity_request_array[mode] == NULL)
        {
            entity_request_array[mode] = entity_request;
        }
        else
        {
            Entity *request_temp = entity_request_array[mode]; 
            entity_request_array[mode] = entity_request;
            entity_request->next = request_temp;
        }
    #endif
}


void
Entity_Request_Array_Free ()
{
    Entity *current_request, *temp_request;

    for (int mode = 0; mode < N_ENTITY_REQUEST_MODE; mode++)
    {
        current_request = entity_request_array[mode];

        while (current_request != NULL)
        {
            temp_request = current_request;
            free (temp_request);
            temp_request = NULL;
            current_request = current_request->next;
        }

        entity_request_array[mode] = NULL;
    }
}


void
Entity_List_Free ()
{
    Entity *temp_entity, *current_entity;

    current_entity = entity_list;

    while (current_entity != NULL)
    {
        temp_entity = current_entity;
        current_entity = current_entity->next;
        free (temp_entity);
        temp_entity = NULL;
    }
}




void
Component_Reset ()
{
    //EntityRequest *current_request = entity_request_list;

    //while (current_request != NULL)
    //{
    //    Entity *current_entity = entity_list;

    //    while (current_entity != NULL)
    //    {
    //        current_entity = current_entity->next;
    //    }

    //    current_request = current_request->next;
    //}
}


// below functions only use for testing purpose
Entity **
Get_Request_Array ()
{
    return entity_request_array;
}


Entity *
Get_Request_List()
{
    return request_list;
}

#endif
