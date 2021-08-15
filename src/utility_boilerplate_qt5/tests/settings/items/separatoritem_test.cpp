#include <gtest/gtest.h>
#include "../../fixtures.hpp"

#include <settings/items/separatoritem.hpp>

namespace ubTestSuit {

    TEST_F(UiFixture, SettingItems_SeparatorItem) {  // NOLINT(cert-err58-cpp)
        auto* item = new SeparatorItem();

        EXPECT_EQ(item->key(), nullptr);

        QWidget* widget = item->view(window);
        EXPECT_NE(widget, nullptr);

        delete item;
    }

}  // namespace ubTestSuit
