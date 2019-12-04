/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


namespace fakeit {

    struct VirtualTableBase {

        static VirtualTableBase &getVTable(void *instance);

        VirtualTableBase(void **firstMethod);

        void *getCookie(int index);

        void setCookie(int index, void *value);

        void *getMethod(unsigned int index) const;

        void setMethod(unsigned int index, void *method);

    protected:
        void **_firstMethod;
    };

 }
