/******************************************************************************
 * Targoman: A robust Machine Translation framework               *
 *                                                                            *
 * Copyright 2014-2018 by ITRC <http://itrc.ac.ir>                            *
 *                                                                            *
 * This file is part of Targoman.                                             *
 *                                                                            *
 * Targoman is free software: you can redistribute it and/or modify           *
 * it under the terms of the GNU Lesser General Public License as published   *
 * by the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                        *
 *                                                                            *
 * Targoman is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU Lesser General Public License for more details.                        *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with Targoman. If not, see <http://www.gnu.org/licenses/>.           *
 *                                                                            *
 ******************************************************************************/
/**
 * @author S. Mohammad M. Ziabary <ziabary@targoman.com>
 */

#include <QExplicitlySharedDataPointer>
#include "libTargomanCommon/Macros.h"

#ifndef TARGOMAN_COMMON_CLSCOUNTANDSPEED_H
#define TARGOMAN_COMMON_CLSCOUNTANDSPEED_H

namespace Targoman{
namespace Common {

FORWARD_DECLARE_PRIVATE(clsCountAndSpeed)

class clsCountAndSpeed
{
public:
    explicit clsCountAndSpeed(quint8 _maxSnapshots = 100, quint64 _initialValue = 0);
    ~clsCountAndSpeed();

    clsCountAndSpeed(const clsCountAndSpeed &_other);

    quint64 inc();
    void reset();
    quint64 count() const;
    double  countPerSecond() const;
    void snapshot(quint16 _secsBetween);

private:
    QExplicitlySharedDataPointer<Private::clsCountAndSpeedPrivate> pPrivate;
};

}
}
#endif // TARGOMAN_COMMON_CLSCOUNTANDSPEED_H
