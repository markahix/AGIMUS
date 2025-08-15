#include "utilities.h"
#include "classes.h"


void parse_args(int argc, char** argv, std::map<std::string, std::vector<std::string>> &flags)
{
    std::string key = "executable";
    for (int i = 0; i < argc; i++)
    {
        std::string flag(argv[i]);
        if (flag[0] == '-')
        {
            key = flag;
            if (flags.count(key) == 0)
            {
                flags[key] = {};
            }
        }
        else
        {
            flags[key].push_back(flag);
        }
    }
}

fs::path GetDroneLocations(std::map<std::string, std::vector<std::string>> flags)
{
    fs::path my_location = fs::absolute(flags["executable"][0]).parent_path().parent_path().parent_path();
    return my_location;
}

int main(int argc, char** argv)
{
    splash_screen();
    // Variable Declarations
    std::map<std::string, std::vector<std::string>> flags;
    parse_args(argc,argv,flags);
    debug_log("Currently in debug mode.");
    
    // Overseer should examine the folder we're in, figure out what's going on, determine what needs to be done
    // See if there are any of the AGIMUS-related input files floating around?
    // - amberinput.in
    // Also need an AGIMUS tracking file...
    // Let's start there.


    // Add AGIMUS Location to path.
    fs::path my_location = GetDroneLocations(flags);
    std::string sys_path = "PATH=";
    sys_path += std::getenv("PATH");
    sys_path += ":";
    sys_path += my_location;
    // std::cout << sys_path << std::endl;
    char *cstr = sys_path.data();
    putenv(cstr);
    std::cout << GetSysResponse("echo $PATH") << std::endl;
    AGIMUSsubmodules drones;

    return 0;
}