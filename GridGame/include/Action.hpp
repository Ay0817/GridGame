#pragma once

#include <functional>
#include <vector>
#include <cstdint>
#include <algorithm>

/// @brief イベントシステム
/// @tparam ...Args イベントの引数の型
template<typename... Args>
class Action final {
public:
	using Func = std::function<void(Args...)>; // 関数の型
	using ID = uint32_t; // ID
private:
	/// @brief イベントリスナー
	struct Listener {
		ID id;     // ID
		Func func; // 関数 
	};

	std::vector<Listener> _listeners; // リスナーのリスト
	std::vector<ID> _toRemove;        // 削除予定のIDのリスト

	ID _nextId = 1;         // 次のID
	bool _invoking = false; // 呼び出し中かどうか
public:
	/// @brief 追加
	/// @param func 関数 
	/// @return ID
	ID Add(Func func) {
		_listeners.push_back({ _nextId, std::move(func) });

		return ++_nextId;
	}

	/// @brief 削除
	/// @param id ID
	void Remove(ID id) {
		if (_invoking) {
			_toRemove.push_back(id);

			return;
		}

		auto it = std::remove_if(_listeners.begin(), _listeners.end(),
			[id](const Listener& listener) {
				return listener.id == id;
			});

		_listeners.erase(it, _listeners.end());
	}

	/// @brief 呼び出し
	/// @param ...args 引数 
	void Invoke(Args... args) {
		_invoking = true;

		for (auto& listener : _listeners) {
			listener.func(args...);
		}

		_invoking = false;

		for (auto id : _toRemove) {
			Remove(id);
		}

		_toRemove.clear();
	}

	/// @brief クリア
	void Clear() {
		_listeners.clear();
	}

	/// @brief リスナーの数
	size_t Count() const {
		return _listeners.size();
	}
};
