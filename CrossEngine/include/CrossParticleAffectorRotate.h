/****************************************************************************
Copyright (c) 2015 LiangYue.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once


#include "CrossEngine.h"


namespace CrossEngine {

	class _CrossExport CAffectorRotate : public CAffectorBase
	{
		friend class CParticleSystem;


		// 构造/析构函数
	protected:
		CAffectorRotate(CParticleSystem *pParent);
		virtual ~CAffectorRotate(VOID);


		// 方法
	public:
		virtual TYPE GetType(VOID) const;                                                          // 获得类型

		virtual VOID Init(VOID);                                                                   // 初始化
		virtual VOID Free(VOID);                                                                   // 释放

		virtual VOID LoadXML(TiXmlNode *pAffectorNode);                                            // 加载XML
		virtual VOID SaveXML(TiXmlNode *pAffectorNode) const;                                      // 保存XML

		virtual VOID Affect(CParticle *pParticle, FLOAT deltaTime);                                // 影响粒子

	public:
		VOID SetRotateSpeed(FLOAT minSpeed, FLOAT maxSpeed);                                       // 设置旋转速度
		FLOAT GetMinRotateSpeed(VOID) const;                                                       // 设置最小旋转速度
		FLOAT GetMaxRotateSpeed(VOID) const;                                                       // 设置最大旋转速度


		// 属性
	protected:
		FLOAT m_minRotateSpeed;                                                                    // 最小旋转速度(弧度/秒)
		FLOAT m_maxRotateSpeed;                                                                    // 最大旋转速度(弧度/秒)
	};

}
