#pragma once

#include <algorithm>
#include <vector>

namespace EventSample
{
	class ReferenceObject
	{
		int ref = 1;

	public:
		ReferenceObject() = default;
		virtual ~ReferenceObject() = default;

		int AddRef()
		{
			ref++;
			return ref;
		}

		int Release()
		{
			ref--;
			auto ret = ref;
			if (ref == 0) delete this;
			return ret;
		}
	};
    
    // 関数ポインタ(デリゲート)
    typedef void(*action_t)();

    // Core のクラス
    class CoreClass : public ReferenceObject
    {
    private:
        // 追加されたクラス
        std::vector<action_t> m_callbacks;

    public:
        // コンストラクタ
        CoreClass();

        // デストラクタ
        ~CoreClass();

        // イベントを追加する
        void AddEvent(action_t callback);

        // イベントを削除する
        void RemoveEvent(action_t callback);

        // イベントを呼び出す
        void CallEvents();
    };
}