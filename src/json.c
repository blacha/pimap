#include <windows.h>
#include <iostream>

bool json_comma_enabled = false;

void json_start()
{
    printf("{");
}
void json_comma()
{
    if (json_comma_enabled)
    {
        printf(", ");
    }
    json_comma_enabled = true;
}
void json_value(int value)
{
    json_comma();
    printf("%d", value);
}
void json_key_raw(char *key)
{
    printf("\"%s\":", key);
}
void json_key_value(char *key, int value)
{
    json_comma();
    json_key_raw(key);
    printf("%d", value);
}
void json_key_value(char *key, char *value)
{
    json_comma();
    json_key_raw(key);
    printf("\"%s\"", value);
}
void json_array_start()
{
    json_comma();
    json_comma_enabled = false;
    printf("[");
}
void json_array_start(char *key)
{
    json_comma();
    json_key_raw(key);
    json_comma_enabled = false;
    printf("[");
}
void json_array_end()
{
    printf("]");
    json_comma_enabled = true;
}

void json_object_start()
{
    json_comma();
    printf("{");
    json_comma_enabled = false;
}
void json_object_start(char *key)
{
    json_comma();
    json_key_raw(key);
    printf("{");
    json_comma_enabled = false;
}
void json_object_end()
{
    printf("}");
    json_comma_enabled = true;
}
void json_end()
{
    printf("}");
}
