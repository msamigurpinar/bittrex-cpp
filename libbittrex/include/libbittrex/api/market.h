#pragma once

#include <memory>
#include <utility>
#include <libbittrex/models/open_order.h>
#include <libbittrex/models/uuid.h>
#include <libbittrex/api/base.h>

using namespace bittrex;

namespace bittrex::api {

using btx_uuid_t = model::Uuid;
using open_order_t = model::OpenOrder;
using open_order_list_t = std::vector<open_order_t>;

class Market : Base {
public:
    explicit Market(const std::shared_ptr<ApiCall> &api_call) : Base(api_call) {}

    /**
     * Used to place a buy order in a specific market.
     * Use buylimit to place limit orders.
     * @param market a string literal for the market (ex: BTC-LTC)
     * @param quantity the amount to purchase
     * @param rate the rate at which to place the order.
     */
    btx_uuid_t buy_limit(const std::string &market, const float &quantity, const float &rate);

    /**
     * Used to place an sell order in a specific market.
     * Use selllimit to place limit orders.
     * @param market a string literal for the market (ex: BTC-LTC)
     * @param quantity the amount to purchase
     * @param rate the rate at which to place the order.
     */
    btx_uuid_t sell_limit(const std::string &market, const float &quantity, const float &rate);

    /**
     * Used to cancel a buy or sell order.
     * @param uuid uuid of buy or sell order
     */
    btx_uuid_t cancel(const std::string &uuid);

    /**
     * Get all orders that you currently have opened. A specific market can be requested
     * @param market optional a string literal for the market (ie. BTC-LTC)
     * */
    open_order_list_t get_open_orders(const std::string &market);

};
} //Namespace Bittrex::api
