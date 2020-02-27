//
// Created by KH on 2/26/2020.
//

#ifndef IGEN3_IGENOPTS_H
#define IGEN3_IGENOPTS_H

#include <string>
#include <memory>


namespace igen {

class IgenOpts {
public:
    IgenOpts(std::string domInp, uint64_t seed, std::string runnerType, std::string target);

    [[nodiscard]] uint64_t getSeed() const;

    [[nodiscard]] const std::string &getRunnerType() const;

    [[nodiscard]] const std::string &getTarget() const;

private:
    std::string domInp_;
public:
    const std::string &getDomInp() const;

private:
    uint64_t seed_;
    std::string runnerType_;
    std::string target_;
};

}


#endif //IGEN3_IGENOPTS_H
