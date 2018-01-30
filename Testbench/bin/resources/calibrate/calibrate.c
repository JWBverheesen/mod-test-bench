#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

/**********************************************************************************************************************************************************/

#define PLUGIN_URI "http://moddevices.com/plugins/mod-devel/calibrate"
typedef enum {IN, OUT}PortIndex;

float dumparray[1000];
float copyarray[1000];
/**********************************************************************************************************************************************************/

typedef struct{
    float *in;
	float *out;
} Switchbox;
/**********************************************************************************************************************************************************/
static LV2_Handle
instantiate(const LV2_Descriptor*   descriptor,
double                              samplerate,
const char*                         bundle_path,
const LV2_Feature* const* features)
{
    Switchbox* switchbox = (Switchbox*)malloc(sizeof(Switchbox));
    return (LV2_Handle)switchbox;
}
/**********************************************************************************************************************************************************/
static void connect_port(LV2_Handle instance, uint32_t port, void *data)
{
    Switchbox* switchbox = (Switchbox*)instance;

    switch ((PortIndex)port)
    {
        case IN:
            switchbox->in = (float*) data;
            break;
		case OUT:
            switchbox->out = (float*) data;
            break;
    }
}
/**********************************************************************************************************************************************************/
void activate(LV2_Handle instance)
{
    // TODO: include the activate function code here
}

/**********************************************************************************************************************************************************/
void run(LV2_Handle instance, uint32_t n_samples)
{
    const Switchbox* switchbox = (const Switchbox*)instance;    

    float *in = switchbox->in;
	float *out = switchbox->out;

    for ( uint32_t i = 0; i < n_samples; i++)
    {
        dumparray[i]=(*in * 10 /5.12357 +340 -10 *1.6754439);
        *out = *in;
        in++;
        out++;

        for (int a = 0; a<1000; a++)
        {
            copyarray[a] = dumparray[a];
        }
    }
}

/**********************************************************************************************************************************************************/
void deactivate(LV2_Handle instance)
{
    // TODO: include the deactivate function code here
}
/**********************************************************************************************************************************************************/
void cleanup(LV2_Handle instance)
{
    free(instance);
}
/**********************************************************************************************************************************************************/
const void* extension_data(const char* uri)
{
    return NULL;
}
/**********************************************************************************************************************************************************/
static const LV2_Descriptor Descriptor = {
    PLUGIN_URI,
    instantiate,
    connect_port,
    activate,
    run,
    deactivate,
    cleanup,
    extension_data
};
/**********************************************************************************************************************************************************/
LV2_SYMBOL_EXPORT
const LV2_Descriptor* lv2_descriptor(uint32_t index)
{
    if (index == 0) return &Descriptor;
    else return NULL;
}
/**********************************************************************************************************************************************************/
