//Shubhayu Shrestha 1001724804
#ifndef CokeMachine_h
#define CokeMachine_h

enum ACTION
{
    OK,
    NOINVENTORY,
    NOCHANGE,
    INSUFFICIENTFUNDS,
    EXACTCHANGE,
    BOXFULL
};

class CokeMachine
{
    public:
        CokeMachine(std::string name, int cost, int change, int inventory)
        {
            //setting machine name
            machineName = name;

            //setting the price of the coke
            CokePrice = cost;

            //setting teh change level
            changeLevel = change;

            //setting the inventory level of the machine
            inventoryLevel = inventory;
        }
        
        std::string getMachineName()
        {
            return machineName;
        }
        
        bool buyACoke(int payment, std::string &change, int &action)
        {
            //initializing local boolean
            bool passFail;
            //checking inventory level
            if (inventoryLevel <= 0)
            {
                passFail = false;
                action = ACTION::NOINVENTORY;
            }
            else
            {
                if (payment == CokePrice) //checking to see if exact change was used
                {
                    passFail = true;
                    inventoryLevel--;
                    changeLevel += CokePrice;
                    action = ACTION::EXACTCHANGE;
                }
                else if (payment > CokePrice) //if payment is greater than price
                {
                    if (changeLevel >= maxChangeCapacity)
                    {
                        action = ACTION::BOXFULL;
                    }
                    else if (changeLevel >= (payment - CokePrice)) // checking if we have enough change to give back
                    {
                        passFail = true;
                        action = ACTION::OK;
                        inventoryLevel--;
                        changeLevel += CokePrice;
                        change = displayMoney(payment - CokePrice);
                    }
                    else
                    {
                        action = ACTION::NOCHANGE;
                        passFail = false;
                    }
                }
                else if (payment < CokePrice) //checking if there is insufficient funds
                {
                    action = ACTION::INSUFFICIENTFUNDS;
                    passFail = false;
                }
            }

            return passFail;
        }
        
        int getInventoryLevel()
        {
            return inventoryLevel;
        }
        
        int getMaxInventoryCapacity()
        {
            return maxInventoryCapacity;
        }

        bool incrementInventory(int amountToAdd)
        {
            int newAmount = inventoryLevel + amountToAdd;
            bool result;

            if (newAmount > maxInventoryCapacity)
            {
                result = false;
            }
            else if (amountToAdd < 0)
            {
                result = false;
            }
            else
            {
                result = true;

                inventoryLevel = newAmount;
            }

            return result;
        }

        std::string getChangeLevel()
        {
            return displayMoney(changeLevel);
        }
        
        bool incrementChangeLevel(int amountToAdd)
        {
            int newChangelevel = changeLevel + amountToAdd;
            bool result;

            if (newChangelevel > maxChangeCapacity)
            {
                result = false;
            }
            else if (amountToAdd < 0)
            {
                result = false;
            }
            else
            {
                result = true;

                changeLevel = newChangelevel;
            }

            return result;
        }

        std::string getMaxChangeCapacity()
        {
            return displayMoney(maxChangeCapacity);
        }

        std::string getCokePrice()
        {
            return displayMoney(CokePrice);
        }

        std::string displayMoney(int amount)
        {
            std::string dollars{std::to_string(amount / 100)};
            std::string cents{std::to_string(abs(amount % 100))};

            std::string price{"$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents};

            return price;
        }

    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity{5000};
        int CokePrice;
        int inventoryLevel;
        int maxInventoryCapacity{100};
};

#endif
