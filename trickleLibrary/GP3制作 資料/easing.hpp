/*
"LINEAR",
"BACK_IN",
"BACK_OUT",
"BACK_INOUT",
"BOUNCE_OUT",
"BOUNCE_IN",
"BOUNCE_INOUT",
"CIRCLE_IN",
"CIRCLE_OUT",
"CIRCLE_INOUT",
"CUBIC_IN",
"CUBIC_OUT",
"CUBIC_INOUT",
"ELASTIC_IN",
"ELASTIC_OUT",
"ELASTIC_INOUT",
"EXPO_IN",
"EXPO_OUT",
"EXPO_INOUT",
"QUAD_IN",
"QUAD_OUT",
"QUAD_INOUT",
"QUART_IN",
"QUART_OUT",
"QUART_INOUT",
"QUINT_IN",
"QUINT_OUT",
"QUINT_INOUT",
"SINE_IN",
"SINE_OUT",
"SINE_INOUT",
*/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include <unordered_map>
#include <functional>
#include <chrono>
#undef max
#undef min

#include <algorithm>
//#include "counter.hpp"



namespace ci_ext
{


// floatの円周率
const float m_pi = static_cast<float>(M_PI);

enum class EasingName
{
    LINEAR,
    BACK_IN,
    BACK_OUT,
    BACK_INOUT,
    BOUNCE_OUT,
    BOUNCE_IN,
    BOUNCE_INOUT,
    CIRCLE_IN,
    CIRCLE_OUT,
    CIRCLE_INOUT,
    CUBIC_IN,
    CUBIC_OUT,
    CUBIC_INOUT,
    ELASTIC_IN,
    ELASTIC_OUT,
    ELASTIC_INOUT,
    EXPO_IN,
    EXPO_OUT,
    EXPO_INOUT,
    QUAD_IN,
    QUAD_OUT,
    QUAD_INOUT,
    QUART_IN,
    QUART_OUT,
    QUART_INOUT,
    QUINT_IN,
    QUINT_OUT,
    QUINT_INOUT,
    SINE_IN,
    SINE_OUT,
    SINE_INOUT
};
inline std::string GetName(const EasingName& n)
{
    std::string name[] 
    {
        "LINEAR",
        "BACK_IN",
        "BACK_OUT",
        "BACK_INOUT",
        "BOUNCE_OUT",
        "BOUNCE_IN",
        "BOUNCE_INOUT",
        "CIRCLE_IN",
        "CIRCLE_OUT",
        "CIRCLE_INOUT",
        "CUBIC_IN",
        "CUBIC_OUT",
        "CUBIC_INOUT",
        "ELASTIC_IN",
        "ELASTIC_OUT",
        "ELASTIC_INOUT",
        "EXPO_IN",
        "EXPO_OUT",
        "EXPO_INOUT",
        "QUAD_IN",
        "QUAD_OUT",
        "QUAD_INOUT",
        "QUART_IN",
        "QUART_OUT",
        "QUART_INOUT",
        "QUINT_IN",
        "QUINT_OUT",
        "QUINT_INOUT",
        "SINE_IN",
        "SINE_OUT",
        "SINE_INOUT",
    };
    return name[static_cast<int>(n)];
}
template <typename T>
using Ease = std::function<T(float, const float, const T&, const T&)>;

// 値を [min_value, max_value] にする
template <typename T>
T clamp(const T& value, const T& min_value, const T& max_value)
{
	return std::max(std::min(value, max_value), min_value);
}

//文字列で指定した関数を返す
// t = 経過時間 b = 始点 c = 終点 - 始点 d = 持続時間 
//これはリークとして感知されるので注意！
template <typename T>
Ease<T> createEase(const std::string& ease_name)
{
	static const std::unordered_map<std::string, Ease<T>> func_table =
	{
		{
			"LINEAR",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return c*t / d + b;
			}
		},

		{
			"BACK_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				float s = 1.70158f;
				t /= d;
				return c*t*t*((s + 1)*t - s) + b;
			}
		},

		{
			"BACK_OUT",
			[](float t, const float b, const float c, const float d)
			{
				float s = 1.70158f;
				t = t / d - 1;
				return c*(t*t*((s + 1)*t + s) + 1) + b;
			}
		},

		{
			"BACK_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				float s = 1.70158f;
				t = t / d - 1;
				return c*(t*t*((s + 1)*t + s) + 1) + b;
			}
		},
		
		{
			"BOUNCE_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d) < (1 / 2.75f)) {
					return c*(7.5625f*t*t) + b;
				}
				else if (t < (2 / 2.75f)) {
					t -= (1.5f / 2.75f);
					return c*(7.5625f*t*t + .75f) + b;
				}
				else if (t < (2.5f / 2.75f)) {
					t -= (2.25f / 2.75f);
					return c*(7.5625f*t*t + .9375f) + b;
				}
				else {
					t -= (2.625f / 2.75f);
					return c*(7.5625f*t*t + .984375f) + b;
				}
			}
		},
		
		{
			"BOUNCE_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return func_table.at("BOUNCE_OUT")(d - t, 0.0f, c, d) + b;
				//return c - EasingBounceOut(d - t, 0.0f, c, d) + b;
			}
		},
		
		{
			"BOUNCE_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if (t < d / 2) return func_table.at("BOUNCE_IN")(t * 2, 0.0f, c, d) * .5f + b;
				else					 return func_table.at("BOUNCE_OUT")(t * 2 - d, 0.0f, c, d) * .5f + c*.5f + b;
			}
		},

		{
			"CIRCLE_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return -c * (std::sqrt(1 - t*t) - 1) + b;
			}
		},

		{
			"CIRCLE_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t = t / d - 1;
				return c * std::sqrt(1 - t*t) + b;
			}
		},

		{
			"CIRCLE_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d / 2) < 1) return -c / 2 * (std::sqrt(1 - t*t) - 1) + b;
				t -= 2;
				return c / 2 * (std::sqrt(1 - t*t) + 1) + b;
			}
		},

		{
			"CUBIC_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return c*t*t*t + b;
			}
		},

		{
			"CUBIC_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t = t / d - 1;
				return c*(t*t*t + 1) + b;
			}
		},

		{
			"CUBIC_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
				t -= 2;
				return c / 2 * (t*t*t + 2) + b;
			}
		},

		{
			"ELASTIC_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if (t == 0)      return b;
				if ((t /= d) == 1) return b + c;
				float p = d*0.3f;

				float a = c;
				float s = p / 4;
				t -= 1;
				return -(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
			}
		},

		{
			"ELASTIC_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if (t == 0)      return b;
				if ((t /= d) == 1) return b + c;
				float p = d*0.3f;

				float a = c;
				float s = p / 4;
				return (a* std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p) + c + b);
			}
		},

		{
			"ELASTIC_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if (t == 0) return b;
				if ((t /= d / 2) == 2) return b + c;
				float p = d*(0.3f*1.5f);

				float a = c;
				float s = p / 4;
				if (t < 1)
				{
					t -= 1;
					return -0.5f*(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
				}
				t -= 1;
				return a * std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)*0.5f + c + b;
			}
		},

		{
			"EXPO_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return (t == 0) ? b : c * std::pow(2.0f, 10.0f * (t / d - 1.0f)) + b;
			}
		},

		{
			"EXPO_OUT",
			[](float t, const float b, const float c, const float d)
			{
				return (t == d) ? b + c : c * (-std::pow(2.0f, -10.0f * t / d) + 1.0f) + b;
			}
		},

		{
			"EXPO_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if (t == 0)         return b;
				if (t == d)         return b + c;
				if ((t /= d / 2) < 1) return c / 2 * std::pow(2.0f, 10.0f * (t - 1.0f)) + b;
				return c / 2 * (-std::pow(2.0f, -10.0f * --t) + 2.0f) + b;
			}
		},

		{
			"QUAD_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return c*t*t + b;
			}
		},

		{
			"QUAD_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return -c *t*(t - 2) + b;
			}
		},

		{
			"QUAD_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d / 2) < 1) return c / 2 * t*t + b;
				--t;
				return -c / 2 * (t*(t - 2) - 1) + b;
			}
		},

		{
			"QUART_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return c*t*t*t*t + b;
			}
		},

		{
			"QUART_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t = t / d - 1;
				return -c * (t*t*t*t - 1) + b;
			}
		},

		{
			"QUART_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
				t -= 2;
				return -c / 2 * (t*t*t*t - 2) + b;
			}
		},

		{
			"QUINT_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t /= d;
				return c*t*t*t*t*t + b;
			}
		},

		{
			"QUINT_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				t = t / d - 1;
				return c*(t*t*t*t*t + 1) + b;
			}
		},

		{
			"QUINT_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);

				if ((t /= d / 2) < 1) return c / 2 * t*t*t*t*t + b;
				t -= 2;
				return c / 2 * (t*t*t*t*t + 2) + b;
			}
		},

		{
			"SINE_IN",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return -c * std::cos(t / d * (m_pi / 2)) + c + b;
			}
		},

		{
			"SINE_OUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return c * std::sin(t / d * (m_pi / 2)) + b;
			}
		},

		{
			"SINE_INOUT",
			[](float t, const float b, const float c, const float d)
			{
				t = clamp(t, 0.0f, d);
				return -c / 2 * (std::cos(m_pi*t / d) - 1) + b;
			}
		}
	};
	return func_table.at(ease_name);
}
//*
template<typename T>
class EaseObj
{
	std::string name_;//イージング名
	T start_;	//始点
	T end_;		//終点
	T duration_;//最大時間
	T elapse_;	//経過時間
	Ease<T> easing_;//関数いれる
	std::chrono::system_clock::time_point  beginTime_;//開始時間保存

public:
	//未使用時はこのコンストラクタを使う
	EaseObj() 
		:
		name_(""),
		start_(T()),
		end_(T()),
		duration_(T()),
		elapse_(T()),
		easing_(nullptr)
	{
	}

	// elapse   = 経過時間 
	// duration = 持続時間
	// start    = 始点
	// end      = 終点 - 始点 
	EaseObj(const std::string& name, T  start, T end, T duration, T elapse = 0.0f)
		:
		name_(name),
		start_(start),
		end_(end),
		duration_(duration),
		elapse_(elapse),
		easing_(name == "" ? (nullptr): createEase<T>(name)),

		beginTime_(std::chrono::system_clock::now())
	{
	}

    EaseObj(EasingName name, T  start, T end, T duration, T elapse = 0.0f)
        :
        EaseObj(GetName(name), start, end, duration, elapse)
    {

    }

    //作成
    void create(const std::string& name, T  start, T end, T duration, T elapse = 0.0f)
    {
        name_  = name;
        start_ = start;
        end_ = end;
        duration_ = duration;
        elapse_ = elapse;
        name == "" ? easing_ = (nullptr) : easing_ = createEase<T>(name);
        beginTime_ = std::chrono::system_clock::now();
    }

    //作成
    void create(EasingName name, T  start, T end, T duration, T elapse = 0.0f)
    {
        create(GetName(name), start, end, duration, elapse);
    }

    void change_target(T end, T duration)
    {
        elapse_ = 0;
        start_ = now();
        end_ = end;
        duration_ = duration;
        beginTime_ = std::chrono::system_clock::now();
    }

    //初期状態に戻す
    void back_head()
    {
        elapse_ = 0;
        beginTime_ = std::chrono::system_clock::now();
    }
    //現在値をintで取得
    int nowi() const
    {
        return static_cast<int>(now());
    }

    //現在値をfloatで取得
    float nowf() const
    {
        return static_cast<float>(now());
    }

    //現在値を定義された型で取得
    T now() const
    {
        clamp<T>(elapse_, 0.0f, duration_);
        return easing_(elapse_, start_, end_, duration_);
    }

    //現在値をintで取得
    int nowi() 
    {
        return static_cast<int>(now());
    }

    //現在値をfloatで取得
    float nowf() 
    {
        return static_cast<float>(now());
    }

    //現在値を定義された型で取得
    T now()
	{
        auto a = std::chrono::system_clock::now() - beginTime_;
        elapse_ = a.count() / 10000000.0f;
        clamp<T>(elapse_, 0.0f, duration_);
		return easing_(elapse_, start_, end_, duration_);
	}

    //現在値を定義された型で取得
    T operator()() const
	{
		return now();
	}

	//イージング関数が設定されているときtrueが返る
	bool valid() const
	{
		return easing_ != nullptr;
	}
};
using Easing = EaseObj<float>;
//*/
}