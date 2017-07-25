//
// Created by Chaz on 6/22/2017.
//

#ifndef DUNGEONENGINE_OSTREAMERRORLISTENER_H
#define DUNGEONENGINE_OSTREAMERRORLISTENER_H


#include <memory>
#include "ErrorListener.h"

class OStreamErrorListener : public ErrorListener{
private:
    std::shared_ptr<std::ostream> mOutputStream;
public:
    OStreamErrorListener() = delete;
    OStreamErrorListener(std::shared_ptr<std::ostream> outputStream);

    virtual void onError(std::string msg) override;
};


#endif //DUNGEONENGINE_OSTREAMERRORLISTENER_H
