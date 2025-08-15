#ifndef CLASSES_H
#define CLASSES_H
#include "utilities.h"

struct ExternalProgram
{
    std::string name;
    std::string full_path;
    std::string module;
    bool is_available;
};

class AGIMUSsubmodules
{
    private:
        std::map<std::string, ExternalProgram> drones;
        fs::path AGIMUStracker;
        ExternalProgram GetProgramData(std::string program_name);
        ExternalProgram GetProgramData(std::string program_name, std::string module_name);
        // bool featurefinder = false;
        // bool datasetbuilder = false;
        // bool autosolvent = false;
        // bool autoquantum = false;
        // bool autoparams = false;
        // bool autommpbsa = false;
        // bool automd = false;
        // bool autoanalytics = false;
        // bool terachem = false;
        // bool pdflatex = false;
        // bool pmemd_cuda = false;
    public:
        void write_tracker();
        AGIMUSsubmodules();
        ~AGIMUSsubmodules();
};

#endif