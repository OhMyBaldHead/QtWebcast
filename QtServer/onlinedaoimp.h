#ifndef ONLINEDAOIMP_H
#define ONLINEDAOIMP_H

#include "onlinedao.h"

class OnlineDaoImp : public OnlineDao
{
public:
    OnlineDaoImp();
    bool addOnline(QString& name,int portid);
    char* findOnline(QString& name);
    bool delOnline(QString& name);
    int getportidOnline(QString& name);
    vector<QString> selectOnline();
private:
    vector<QString> onlines;
};

#endif // ONLINEDAOIMP_H
