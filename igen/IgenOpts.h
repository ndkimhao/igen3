//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_IGENOPTS_H
#define IGEN3_IGENOPTS_H

#include <string>
#include <memory>

#include "runner/Runner.h"
#include "DomainFile.h"

namespace igen {

class IgenOpts {
public:
    IgenOpts(std::string domInp, uint64_t seed, std::string runnerType, std::string target);

    [[nodiscard]] const std::string &getDomInp() const;

    [[nodiscard]] uint64_t getSeed() const;

    [[nodiscard]] const std::string &getRunnerType() const;

    [[nodiscard]] const std::shared_ptr<Runner> &getRunner() const;

    [[nodiscard]] const std::string &getTarget() const;

private:
    std::string domInpPath_;
    DomainFile domFile_;
    uint64_t seed_;
    std::string runnerType_;
    std::shared_ptr<Runner> runner_;
    std::string target_;
};

}


#endif //IGEN3_IGENOPTS_H
