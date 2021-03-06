//
// Created by Vincent Tan on 11/29/21.
//

#ifndef DAPPF_SPOOLER_H
#define DAPPF_SPOOLER_H

#include <vector>
#include <string>
#include <exception>
#include "predictor.h"
#include "../event_listeners/on_internal_error.h"
#include "../handlers/handler.h"
#include "../handlers/handler_director.h"
#include "../../constants.h"
#include "../../data/storage/cache.h"

namespace dappf::data::spooler {
    class spooler {
    private:
        static dappf::data::handlers::handler* fetch_handler(int);
    public:
        static void spool(std::string, int);
    };
}


#endif //DAPPF_SPOOLER_H
