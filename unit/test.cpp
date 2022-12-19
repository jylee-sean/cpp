#include <iostream>
#include <cmath>
#include <ratio>

namespace phy
{
	namespace units
	{
		template<typename T, typename U = std::ratio<1>>
		class quantity
		{
		public:
			typedef T _rep;
			typedef U _ratio;
			explicit quantity(const T& r = T(0)) : _r(r) { }
			constexpr T value() const { return _r; }
		private:
			T _r;
		};

		template<typename TO, typename T, typename U>
		constexpr TO _cast(const quantity<T, U>& from) {
			return TO(from.value() * U::num * TO::_ratio::den / U::den / TO::_ratio::num);
		}

		template<typename T, typename U = std::ratio<1>>
		class angle : public quantity<T, U> {
		public:
			explicit angle(const T& r = T(0)) : quantity<T, U>(r) { }

			angle operator+(const angle& rhs) {
				return angle(this->value() + rhs.value());
			}

			angle operator-(const angle& rhs) {
				return angle(this->value() - rhs.value());
			}
		};

		constexpr std::intmax_t _pi_res = 1000000;
		typedef units::angle<double>						degree;
		typedef units::angle<double, std::ratio<360,1>>		turn;
		typedef units::angle<double, std::ratio<180 * _pi_res, static_cast<std::intmax_t>(M_PI * _pi_res)>> radian;

		template<typename TO, typename T, typename U>
		constexpr TO angle_cast(const angle<T, U>& from) { return _cast<TO>(from); }

		template<typename T, typename U = std::ratio<1>>
		class length : public quantity<T, U> {
		public:
			explicit length(const T& r = T(0)) : quantity<T, U>(r) { }

			length operator+(const length& rhs) {
				return length(this->value() + rhs.value());
			}

			length operator-(const length& rhs) {
				return length(this->value() - rhs.value());
			}
		};

		typedef units::length<double>					meter;
		typedef units::length<double, std::milli>		millimeter;
		typedef units::length<double, std::micro>		micrometer;

		template<typename TO, typename T, typename U>
		constexpr TO length_cast(const length<T, U>& from) { return _cast<TO>(from); }

		typedef std::ratio<1> per_second;
		typedef std::milli per_millisecond;
		typedef std::micro per_microsecond;

		template<typename T, typename D = per_second>
		class velocity : public quantity<typename T::_rep, typename T::_ratio> {
		public:
			typedef D _derivative;
			explicit velocity(const typename T::_rep& r = typename T::_rep(0)) : quantity<typename T::_rep, typename T::_ratio>(r) { }
		};

		template<typename TO, typename TD, typename T, typename U, typename D>
		constexpr TO velocity_cast(const velocity<angle<T, U>, D>& from) {
			return TO(from.value()
					* U::num * D::num * TD::den * TO::_ratio::den
					/ U::den / D::den / TD::num / TO::_ratio::num);
		}

		template<typename TO, typename TD, typename T, typename U, typename D>
		constexpr TO velocity_cast(const velocity<length<T, U>, D>& from) {
			return TO(from.value()
					* U::num * D::num * TD::den * TO::_ratio::den
					/ U::den / D::den / TD::num / TO::_ratio::num);
		}
	}
}



int main()
{

    std::cout<< phy::units::velocity<phy::units::millimeter,std::ratio<1,2>>(10.0).value() <<std::endl;
    //std::cout<< phy::units::velocity<phy::units::millimeter>(10.0).value() <<std::endl;


		//double value = 5.0;

	//phy::units::quantity<double> quantity_1();
	//phy::units::quantity<double> quantity_2(1.0);
	//phy::units::quantity<double> quantity_3(value);
	//phy::units::quantity<double, std::ratio<2,4>> quantity_4();
	std::cout<< phy::units::quantity<double, std::ratio<3,5>> quantity_5(2.0) <<std::endl;;
	//phy::units::quantity<double, std::ratio<9,8>> quantity_6(value);




	//std::cout<<quantity_6(value).value()<<std::endl;
    return 0;
}

