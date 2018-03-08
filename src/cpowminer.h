#ifndef CPOWMINER_H
#define CPOWMINER_H

class CWallet;
class CPowMiner
{
public:
    CPowMiner();
    void GenerateBitcoins(bool fGenerate, CWallet* pwallet);
};

#endif // CPOWMINER_H
