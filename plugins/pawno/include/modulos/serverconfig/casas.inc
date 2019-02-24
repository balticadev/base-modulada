funcion CargarCasa(casaid,name[],value[])
{
new string[250];
INI_Int("Propietario",cInfo[casaid][cPro]);
INI_Int("Comprada",cInfo[casaid][cComp]);
INI_Int("Cerradura",cInfo[casaid][cCerradura]);
INI_Float("Coordenada X",cInfo[casaid][cx]);
INI_Float("Coordenada Y",cInfo[casaid][cy]);
INI_Float("Coordenada Z",cInfo[casaid][cz]);
INI_Float("Int Coor X",cInfo[casaid][ix]);
INI_Float("Int Coor Y",cInfo[casaid][iy]);
INI_Float("Int Coor Z",cInfo[casaid][iz]);
cInfo[casaid][cID] = CreateDynamicPickup(19134, 1,cInfo[casaid][cx], cInfo[casaid][cy], cInfo[casaid][cz], 0, 0);
AumetarC();
if(cInfo[casaid][cComp] == 1)
{
format(string, sizeof(string), "[Casa Con Propietario]\n{FFFFFF}Casa de {00A400} %s\n{FFFFFF}ID: {00A400}%d",cInfo[casaid][cPro], casaid);
CasaLabel[casaid] = CreateDynamic3DTextLabel(string, Color_Blanco, cInfo[casaid][cx], cInfo[casaid][cy], cInfo[casaid][cz]+0.5,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0,-1,-1, 100.0);
}
else{
format(string, sizeof(string), "[Casa Sin Propietario]\n{FFFFFF}ID: {00A400}%d\n{FFFFFF}¡ Utiliza el comando {00A400}/comprarcasa !", casaid);
CasaLabel[casaid] = CreateDynamic3DTextLabel(string, Color_Blanco,  cInfo[casaid][cx], cInfo[casaid][cy], cInfo[casaid][cz]+0.5,10.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0,-1,-1, 100.0);
}
return 1;
}