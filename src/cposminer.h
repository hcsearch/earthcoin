#ifndef CPOSMINER_H
#define CPOSMINER_H
#include <boost/thread/thread.hpp>

class CWallet;
class CPosMiner
{
public:
    CPosMiner();
    ~CPosMiner();
    void GenerateBitcoins(bool fGenerate, CWallet* pwallet);
private:
    boost::thread_group *m_pPosMinerThreads;
};

#endif // CPOSMINER_H
