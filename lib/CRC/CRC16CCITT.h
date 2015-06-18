#ifndef CRC16CCITT_H
#define CRC16CCITT_H

#include "CRC/CRC.h"

class CRC16CCITT : public CRC
{
    public:
        CRC16CCITT();

    protected:
        virtual CRCType getPolynomial() const;
        virtual CRCType getPolynomialReverse() const;
        virtual size_t getNumBytes() const;
        virtual CRCType makeNextChecksum(CRCType prevChecksum, uint8_t c) const;
        virtual CRCType makePrevChecksum(CRCType nextChecksum, uint8_t c) const;

        virtual CRCType computePatch(
            CRCType targetChecksum,
            File::OffsetType targetPosition,
            File &inputFile,
            bool overwrite) const;

    private:
        uint16_t lookupTable[256];
        uint16_t invLookupTable[256];
};

#endif