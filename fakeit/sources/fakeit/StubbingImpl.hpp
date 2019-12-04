/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


namespace fakeit {

    template<typename C, typename DATA_TYPE>
    class DataMemberStubbingRoot {
    private:
        //DataMemberStubbingRoot & operator= (const DataMemberStubbingRoot & other) = delete;
    public:
        DataMemberStubbingRoot(const DataMemberStubbingRoot &) = default;

        DataMemberStubbingRoot() = default;

        void operator=(const DATA_TYPE&) {
        }
    };

}
