#pragma once

#include <functional>

/// @brief トランジションを管理するクラス
class TransitionManager final {
private:
    /// @brief トランジションの状態
    enum class State {
        None,
        FadeOut,
        Switch,
        FadeIn
    };
private:
    State state = State::None;

    float timer = 0.f;
    float duration = 0.75f;

    std::function<void()> onChange;

    static TransitionManager instance;
private:
    /// @brief 内部用の開始時処理
    void Begin(std::function<void()> func);

    /// @brief 内部用の更新処理
    void UpdateImpl();

    /// @brief 内部用の描画処理
    void DrawImpl() const;

    /// @brief イージング
    /// @param t 0 から 1 までの値
    /// @return イージングされた値
    float Ease(float t) const;
public:
    /// @brief トランジションを開始
    static void Play(std::function<void()> func) {
        if (instance.state != State::None) {
            return;
        }

        instance.Begin(func);
    }

    /// @brief 更新処理
    static void Update() {
        instance.UpdateImpl();
    }

    /// @brief 描画処理
    static void Draw() {
        instance.DrawImpl();
    }

    /// @brief トランジション中かどうか
    /// @return トランジション中なら true、そうでなければ false
    static bool IsPlaying() {
        return instance.state != State::None;
    }
};
