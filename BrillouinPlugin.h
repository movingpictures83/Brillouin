#ifndef BRILLOUINPLUGIN_H
#define BRILLOUINPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class BrillouinPlugin : public Plugin
{
public: 
 std::string toString() {return "Brillouin";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
