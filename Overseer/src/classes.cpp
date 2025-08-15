#include "classes.h"

void AGIMUSsubmodules::write_tracker()
{
    write_to_file(AGIMUStracker, "#############################\n");
    append_to_file(AGIMUStracker,"# AGIMUS TRACKING PROTOCOLS #\n");
    append_to_file(AGIMUStracker,"#############################\n");
    append_to_file(AGIMUStracker,"%DRONES");
    
    if (drones["featurefinder"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: featurefinder\n");}
    if (drones["datasetbuilder"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: datasetbuilder\n");}
    if (drones["autosolvent"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: autosolvent\n");}
    if (drones["autoquantum"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: autoquantum\n");}
    if (drones["autoparams"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: autoparams\n");}
    if (drones["autommpbsa"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: autommpbsa\n");}
    if (drones["automd"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: automd\n");}
    if (drones["autoanalytics"].is_available) {append_to_file(AGIMUStracker,"DRONE AVAILABLE: autoanalytics\n");}
    if (drones["terachem"].is_available) {append_to_file(AGIMUStracker,"PROGRAM AVAILABLE: terachem\n");}
    if (drones["pdflatex"].is_available) {append_to_file(AGIMUStracker,"PROGRAM AVAILABLE: pdflatex\n");}
    if (drones["pmemd"].is_available) {append_to_file(AGIMUStracker,"PROGRAM AVAILABLE: pmemd.cuda\n");}
}

ExternalProgram AGIMUSsubmodules::GetProgramData(std::string program_name)
{
    ExternalProgram prog;
    prog.name = program_name;
    prog.is_available = CheckProgAvailable(program_name);
    prog.full_path = "";
    prog.module = "";
    if (prog.is_available)
    {
        prog.full_path = GetSysResponse("which " + program_name);
    }
    return prog;
}

ExternalProgram AGIMUSsubmodules::GetProgramData(std::string program_name, std::string module_name)
{
    ExternalProgram prog;
    prog.name = program_name;
    prog.is_available = CheckProgAvailable(program_name, module_name);
    prog.full_path = "";
    prog.module = module_name;
    if (prog.is_available)
    {
        prog.full_path = GetSysResponse("module load " + module_name + "; which " + program_name);
    }
    return prog;
}

AGIMUSsubmodules::AGIMUSsubmodules()
{
    drones = {};
    AGIMUStracker = fs::absolute("./.AGIMUStracker");
    drones["featurefinder"] = GetProgramData("featurefinder");
    drones["datasetbuilder"] = GetProgramData("datasetbuilder");
    drones["autosolvent"] = GetProgramData("autosolvent");
    drones["autoquantum"] = GetProgramData("autoquantum");
    drones["autoparams"] = GetProgramData("autoparams");
    drones["autommpbsa"] = GetProgramData("autommpbsa");
    drones["automd"] = GetProgramData("automd");
    drones["autoanalytics"] = GetProgramData("autoanalytics");
    drones["terachem"] = GetProgramData("terachem",DEFAULT_TERACHEM_MODULE);
    drones["pdflatex"] = GetProgramData("pdflatex",DEFAULT_PDFLATEX_MODULE);
    drones["pmemd"] = GetProgramData("pmemd.cuda",DEFAULT_AMBER_MODULE);

    if ( ! fs::exists(AGIMUStracker))
    {
        write_tracker();
    }
}
AGIMUSsubmodules::~AGIMUSsubmodules()
{
    
}