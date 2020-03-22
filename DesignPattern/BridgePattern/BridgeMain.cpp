//
// Created by xiemenghui on 2018/7/21.
//

#include "BridgeMain.h"

void BridgeMain()
{
    // ������������ơ�����ȣ�
    IElectricalEquipment * light = new Light();
    IElectricalEquipment * fan = new Fan();

    // �������أ�����ʽ���ء���λ���أ�
    // ������ʽ���غ͵�ƹ�����������λ���غͷ��ȹ�������
    ISwitch * pullChain = new PullChainSwitch(light);
    ISwitch * twoPosition = new TwoPositionSwitch(fan);

    // ���ơ��ص�
    pullChain->On();
    pullChain->Off();

    // �򿪷��ȡ��رշ���
    twoPosition->On();
    twoPosition->Off();

    SAFE_DELETE(twoPosition);
    SAFE_DELETE(pullChain);
    SAFE_DELETE(fan);
    SAFE_DELETE(light);
}