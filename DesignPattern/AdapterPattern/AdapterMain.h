//
// Created by xiemenghui on 2018/7/20.
//

#ifndef DESIGNPATTERN_ADAPTERMAIN_H
#define DESIGNPATTERN_ADAPTERMAIN_H

#include "adapter.h"

void AdapterMain()
{
    // ����������
    IRussiaSocket * pAdapter = new PowerAdapter();

    // ���
    pAdapter->Charge();

    SAFE_DELETE(pAdapter);
}

#endif //DESIGNPATTERN_ADAPTERMAIN_H
