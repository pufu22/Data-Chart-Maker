#ifndef PIE_DATA_H
#define PIE_DATA_H

#include<vector>
#include<string>
#include<QJsonObject>
#include<QJsonArray>

class pie_data
{

public:
    pie_data();
    pie_data(std::vector<int>s1,std::vector<std::string>s2,std::string s3);
    std::vector<std::string> etichette;
    std::vector<int> valori;
    std::string title;
    pie_data& operator =(const pie_data& other);
};

#endif // PIE_DATA_H
