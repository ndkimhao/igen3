#include <iostream>
#include <klog.h>

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
    START_EASYLOGGINGPP(argc, argv);
    el::Configurations conf("logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);

    LOG_IF(1 < 2, INFO, "ads") << "  asd";

    return 0;
}
