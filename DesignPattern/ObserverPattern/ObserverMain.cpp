//
// Created by xiemenghui on 2018/7/21.
//

#include "ObserverMain.h"

void ObserverMain()
{
    // ��������
    ConcreteSubject * pSubject = new ConcreteSubject();

    // �����۲���
    IObserver * pObserver1 = new ConcreteObserver("Jack Ma");
    IObserver * pObserver2 = new ConcreteObserver("Pony");

    // ע��۲���
    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);

    // ���ļ۸񣬲�֪ͨ�۲���
    pSubject->SetPrice(12.5);
    pSubject->Notify();

    // ע��һ���۲���
    pSubject->Detach(pObserver2);

    // �ٴθ���״̬����֪ͨ�۲���
    pSubject->SetPrice(15.0);
    pSubject->Notify();

    SAFE_DELETE(pObserver1);
    SAFE_DELETE(pObserver2);
    SAFE_DELETE(pSubject);
}