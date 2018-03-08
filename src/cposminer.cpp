#include "cposminer.h"
#include "util.h"
#include <QDebug>

using namespace boost;

CPosMiner::CPosMiner()
{
    m_pPosMinerThreads = new boost::thread_group;
}

CPosMiner::~CPosMiner()
{
    m_pPosMinerThreads->interrupt_all();
    m_pPosMinerThreads->join_all();
    delete m_pPosMinerThreads;
    m_pPosMinerThreads = nullptr;
}

void static ThreadStakeMinter(void *arg)
{
    RenameThread("stakeminer-thread");
    try
    {
        while(true)
        {
           boost::this_thread::interruption_point();
        }
    }
    catch(...)
    {
         qDebug() << "Interrupt exception was thrown.";
    }
    qDebug() << "exiting\n" ;
}

void CPosMiner::GenerateBitcoins(bool fGenerate, CWallet* pwallet)
{
    if(fGenerate && pwallet)
    {
        m_pPosMinerThreads->create_thread(boost::bind(&ThreadStakeMinter,pwallet));
    }
    else
    {
        m_pPosMinerThreads->interrupt_all();
        m_pPosMinerThreads->join_all();
    }
}
