#pragma once


namespace fakeit {

    struct MethodProxy {

        MethodProxy(unsigned int id, unsigned int offset, void *vMethod);

        unsigned int getOffset() const;

        unsigned int getId() const;

        void *getProxy() const;

    private:
        unsigned int _id;
        unsigned int _offset;
        void *_vMethod;
    };
}