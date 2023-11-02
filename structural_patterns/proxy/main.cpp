#include <iostream>

// Proxy structural design patterns provides a surrogate or placeholder 
// for another object to control access to it.
//
// For example: We create a log proxy object to debug all access to 
// other class.


class DataBaseInterface
{
public:
    /**
     * @param - SQL query
     * @returns - string containing the query result
    */
    virtual std::string Query(std::string query) = 0;

    virtual ~DataBaseInterface() = default;
};

class DataBase : public DataBaseInterface
{
public:
    std::string Query(std::string query) override
    {
        return std::string{"query_result"};
    }

    ~DataBase()
    {

    }
};

class DataPaceLoggingProxy : public DataBaseInterface
{
public:
    DataPaceLoggingProxy(DataBaseInterface *db): mDb(db)
    {

    }

    std::string Query(std::string query) override
    {
        std::cout << "Query log: " << query << std::endl;
        return mDb->Query(query);
    }

    ~DataPaceLoggingProxy()
    {
        
    }

private:
    DataBaseInterface *mDb;
};

int main()
{
    DataBaseInterface *realDb = new DataBase();
    DataBaseInterface *dbLoggerProxy = new DataPaceLoggingProxy(realDb);

    dbLoggerProxy->Query("this_is_a_query");

    delete realDb;
    delete dbLoggerProxy;

    return 0;
}