#ifndef TRADER_H
#define TRADER_H

#include "marketDataDelegate.hpp"
#include "orderDelegate.hpp"
#include "order.hpp"



namespace webbtraders
{
    class market;
    class orderManagement;

    class trader :
        public std::enable_shared_from_this<trader>,
        public marketDataDelegate,
        public orderDelegate
    {
    public:

        //! Default constructor
        trader(market& p_market) noexcept;
        
        //! send order to the market
        /*
          template<typename... Args>
          bool sendOrder(Args... args)
            {
            return  m_orderManagementEngine.sendOrder(std::forward<Args>(args)...);
            // m_market->addTrader(this);
                //createOrder(params);
            }
        */
        //   template<typename... Args>
        // bool sendOrder(Args... args);
        bool sendOrder( unsigned int p_volume, double p_price, orderSide p_side );
        //! Copy constructorx
        //  trader(const trader &other);

        //! Move constructor
        // trader(trader &&other);

        //! Destructor
         ~trader() = default;

        //! Copy assignment operator
        // trader& operator=(const trader &other);

        //! Move assignment operator
        // trader& operator=(trader &&other) noexcept;

    private:
        //  virtual void onTrade() override;
        unsigned int m_ID{0};
        static unsigned int m_counter;
        orderManagement& m_orderManagement;


        virtual void onOrderExecution(const orderExecution& p_orderExcution ) override;
        virtual void onPublicTrade() override;
        virtual void onOrderBook( const std::vector<order>& p_orderBook ) override;

    };

}  // webbtraders

#endif /* TRADER_H */
