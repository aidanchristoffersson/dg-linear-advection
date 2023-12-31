// Created by Aidan Christoffersson on 2023-06-13.

#include <iostream>
#include <tuple>


// Gauss-Legendre nodes and weights storage for all prospective orders
template <size_t N> // order
struct storedGLobatto
{
    const double nodes[N + 1];
    const double weights[N + 1];
};

static const storedGLobatto<1> Order1 = {{-1, 1},
                                   {1, 1}};

static const storedGLobatto<2> Order2 = {{-1, 0, 1},
                                   {0.3333333333333333333333, 1.333333333333333333333,0.3333333333333333333333}};

static const storedGLobatto<3> Order3 = {{-1, -0.447213595499957939282,
                                                 0.447213595499957939282, 1},

                                   {0.1666666666666666666667, 0.8333333333333333333333,
                                           0.8333333333333333333333, 0.1666666666666666666667}};

static const storedGLobatto<4> Order4 = {{-1, -0.6546536707079771437983,
                                           0, 0.654653670707977143798, 1},

                                   {0.1, 0.544444444444444444444,
                                           0.7111111111111111111111, 0.544444444444444444444,
                                           0.1}};

static const storedGLobatto<5> Order5 = {{-1, -0.765055323929464692851,
                                                 -0.2852315164806450963142, 0.2852315164806450963142,
                                                 0.765055323929464692851, 1},

                                   {0.06666666666666666666667, 0.3784749562978469803166,
                                           0.5548583770354863530167, 0.5548583770354863530167,
                                           0.3784749562978469803166, 0.06666666666666666666667}};

static const storedGLobatto<6> Order6 = {{-1, -0.830223896278566929872,
                                          -0.4688487934707142138038, 0, 0.468848793470714213804,
                                          0.830223896278566929872, 1},

                                   {0.04761904761904761904762, 0.276826047361565948011,
                                           0.4317453812098626234179, 0.487619047619047619048,
                                           0.4317453812098626234179, 0.276826047361565948011,
                                           0.04761904761904761904762}};

static const storedGLobatto<7> Order7 = {{-1, -0.8717401485096066153375,
                                                 -0.5917001814331423021445, -0.2092992179024788687687,
                                                 0.2092992179024788687687, 0.5917001814331423021445,
                                                 0.8717401485096066153375, 1},

                                   {0.03571428571428571428571, 0.210704227143506039383,
                                           0.3411226924835043647642, 0.4124587946587038815671,
                                           0.4124587946587038815671, 0.3411226924835043647642,
                                           0.210704227143506039383, 0.03571428571428571428571}};

static const storedGLobatto<8> Order8 = {{-1, -0.8997579954114601573124,
                                           -0.6771862795107377534459, -0.3631174638261781587108, 0,
                                           0.3631174638261781587108, 0.6771862795107377534459,
                                           0.8997579954114601573124, 1},

                                   {0.02777777777777777777778, 0.1654953615608055250463,
                                           0.274538712500161735281, 0.3464285109730463451151,
                                           0.3715192743764172335601, 0.3464285109730463451151,
                                           0.274538712500161735281, 0.1654953615608055250463,
                                           0.02777777777777777777778}};

static const storedGLobatto<9> Order9 = {{-1, -0.9195339081664588138289,
                                           -0.7387738651055050750031, -0.4779249498104444956612,
                                           -0.1652789576663870246262, 0.1652789576663870246262,
                                           0.4779249498104444956612, 0.7387738651055050750031,
                                           0.9195339081664588138289, 1},

                                   {0.02222222222222222222222, 0.1333059908510701111262,
                                           0.2248893420631264521195, 0.2920426836796837578756,
                                           0.3275397611838974566565, 0.3275397611838974566565,
                                           0.2920426836796837578756, 0.2248893420631264521195,
                                           0.1333059908510701111262, 0.02222222222222222222222}};

static const storedGLobatto<10> Order10 = {{-1, -0.9340014304080591343323,
                                             -0.7844834736631444186224, -0.565235326996205006471,
                                             -0.2957581355869393914319, 0, 0.2957581355869393914319,
                                             0.565235326996205006471, 0.7844834736631444186224,
                                             0.9340014304080591343323, 1},

                                     {0.01818181818181818181818, 0.109612273266994864461,
                                             0.1871698817803052041081, 0.2480481042640283140401,
                                             0.286879124779008088679, 0.3002175954556906937859,
                                             0.286879124779008088679, 0.2480481042640283140401,
                                             0.1871698817803052041081, 0.109612273266994864461,
                                             0.01818181818181818181818}};

static const std::tuple<storedGLobatto<1>, storedGLobatto<2>, storedGLobatto<3>, storedGLobatto<4>, storedGLobatto<5>, storedGLobatto<6>,
        storedGLobatto<7>, storedGLobatto<8>, storedGLobatto<9>, storedGLobatto<10>> storedLOrders =
        std::make_tuple(Order1, Order2, Order3, Order4, Order5, Order6, Order7, Order8, Order9, Order10);


template<size_t N>
storedGLobatto<N> GaussLobatto()
{
    return std::get<N - 1>(storedLOrders);
}
