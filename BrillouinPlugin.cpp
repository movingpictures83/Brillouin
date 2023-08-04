#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BrillouinPlugin.h"

void BrillouinPlugin::input(std::string file) {
 inputfile = file;
}

void BrillouinPlugin::run() {

}

void BrillouinPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime diversity alpha --i-table "+inputfile+" --p-metric brillouin_d --o-alpha-diversity "+file+"; unzip -jo "+file+" -d "+PluginManager::prefix()+"; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<BrillouinPlugin> BrillouinPluginProxy = PluginProxy<BrillouinPlugin>("Brillouin", PluginManager::getInstance());
