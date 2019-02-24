/*******************************************************************************

    DesingMyCry
    Shyny
                A_CMD
                    PROCESADOR DE COMANDOS
                    
                v0.1 - 25 04 2013

*******************************************************************************/

#include <a_samp>

#if defined _acmd_included
    #endinput
#endif
#define _acmd_included

#define COMMAND:%1(%2)          \
            forward c_%1(%2); \
            public c_%1(%2)

#define CMD:%1(%2) \
            COMMAND:%1(%2)

#define command(%1,%2,%3) \
            COMMAND:%1(%2, %3)

#define cmd(%1,%2,%3) \
            COMMAND:%1(%2, %3)

#if !defined isnull
    #define isnull(%1) \
                (%1[0] == '#')
#endif

#define MAX_CMD_LEN 32

forward OnPlayerCommandB(playerid, cmdtext[]);
forward OnPlayerCommandUse(playerid, cmdtext[], bool:existe);

public OnPlayerCommandText(playerid, cmdtext[])
{
    CallLocalFunction("OnPlayerCommandB", "is", playerid, cmdtext);
    new e, bool:ex=false, exi, cmdtext_[MAX_CMD_LEN], tcmd[MAX_CMD_LEN];
    strcat(cmdtext_, cmdtext[1], sizeof cmdtext_);
    for(new l = 0; l < strlen(cmdtext_); l++)
    {
        if(cmdtext_[l] == ' '){ e = l; ex=true; strdel(cmdtext_, l, MAX_CMD_LEN+1); break;}
    }
    format(tcmd, sizeof tcmd, "c_%s", cmdtext_);
    if(ex != false){ exi = CallLocalFunction(tcmd, "is", playerid, cmdtext[e+2]); }
    else{ exi = CallLocalFunction(tcmd, "is", playerid, "#"); }

    switch(exi)
    {
        case 0: CallLocalFunction("OnPlayerCommandUse", "isb", playerid, cmdtext, false);
        default: CallLocalFunction("OnPlayerCommandUse", "isb", playerid, cmdtext, true);
    }
    
    return 1;
}

#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText acmd_OnPlayerCommandText
forward acmd_OnPlayerCommandText(playerid, cmdtext[]);