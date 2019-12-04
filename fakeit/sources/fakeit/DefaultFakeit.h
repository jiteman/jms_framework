/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#include "fakeit/DefaultEventFormatter.h"
#include "fakeit/AbstractFakeit.h"


namespace fakeit {

    class DefaultFakeit : public AbstractFakeit {
        DefaultEventFormatter _formatter;
        fakeit::EventFormatter *_customFormatter;
        fakeit::EventHandler *_testingFrameworkAdapter;

    public:
        DefaultFakeit();
        virtual ~DefaultFakeit() = default;
        void setCustomEventFormatter(fakeit::EventFormatter &customEventFormatter);
        void resetCustomEventFormatter();
        void setTestingFrameworkAdapter(fakeit::EventHandler &testingFrameforkAdapter);
        void resetTestingFrameworkAdapter();

    protected:
        fakeit::EventHandler &getTestingFrameworkAdapter() override;
        EventFormatter &getEventFormatter() override;
        EventFormatter &accessEventFormatter() override;

    };
}
