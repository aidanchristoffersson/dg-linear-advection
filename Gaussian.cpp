// Created by Aidan Christoffersson on 2023-06-13.

#include <iostream>
#include <tuple>


    // Gauss-Legendre nodes and weights storage for all prospective orders
    template <size_t N> // order
    struct storedGL
    {
        const double nodes[N + 1];
        const double weights[N + 1];
    };

    static const storedGL<1> Order1 = {{-0.5773502691896257645091488, 0.5773502691896257645091488},
                            {1, 1}};

    static const storedGL<2> Order2 = {{-0.7745966692414833770358531, 0, 0.7745966692414833770358531},
        {0.5555555555555555555555556, 0.8888888888888888888888889,0.5555555555555555555555556}};

    static const storedGL<3> Order3 = {{-0.8611363115940525752239465, -0.3399810435848562648026658,
                              0.3399810435848562648026658, 0.8611363115940525752239465},

                              {0.3478548451374538573730639, 0.6521451548625461426269361,
                                      0.6521451548625461426269361, 0.3478548451374538573730639}};

    static const storedGL<4> Order4 = {{-0.9061798459386639927976269, -0.5384693101056830910363144,
                           0, 0.5384693101056830910363144, 0.9061798459386639927976269},

                             {0.2369268850561890875142640, 0.4786286704993664680412915,
                                     0.5688888888888888888888889, 0.4786286704993664680412915,
                                     0.2369268850561890875142640}};

    static const storedGL<5> Order5 = {{-0.9324695142031520278123016, -0.6612093864662645136613996,
                           -0.2386191860831969086305017, 0.2386191860831969086305017,
                                  0.6612093864662645136613996, 0.9324695142031520278123016},

                          {0.1713244923791703450402961, 0.3607615730481386075698335,
                           0.4679139345726910473898703, 0.4679139345726910473898703,
                                  0.3607615730481386075698335, 0.1713244923791703450402961}};

    static const storedGL<6> Order6 = {{-0.9491079123427585245261897, -0.7415311855993944398638648,
                           -0.4058451513773971669066064, 0, 0.4058451513773971669066064,
                           0.7415311855993944398638648, 0.9491079123427585245261897},

                          {0.1294849661688696932706114, 0.2797053914892766679014678,
                           0.3818300505051189449503698, 0.4179591836734693877551020,
                           0.3818300505051189449503698, 0.2797053914892766679014678,
                           0.1294849661688696932706114}};

    static const storedGL<7> Order7 = {{-0.9602898564975362316835609, -0.7966664774136267395915539,
                                  -0.5255324099163289858177390, -0.1834346424956498049394761,
                                  0.1834346424956498049394761, 0.5255324099163289858177390,
                                  0.7966664774136267395915539, 0.9602898564975362316835609},

                          {0.1012285362903762591525314, 0.2223810344533744705443560,
                                  0.3137066458778872873379622, 0.3626837833783619829651504,
                                  0.3626837833783619829651504, 0.3137066458778872873379622,
                                  0.2223810344533744705443560, 0.1012285362903762591525314}};

    static const storedGL<8> Order8 = {{-0.9681602395076260898355762, -0.8360311073266357942994298,
                           -0.6133714327005903973087020, -0.3242534234038089290385380, 0,
                           0.3242534234038089290385380, 0.6133714327005903973087020,
                           0.8360311073266357942994298, 0.9681602395076260898355762},

                          {0.0812743883615744119718922, 0.1806481606948574040584720,
                           0.2606106964029354623187429, 0.3123470770400028400686304,
                           0.3302393550012597631645251, 0.3123470770400028400686304,
                           0.2606106964029354623187429, 0.1806481606948574040584720,
                           0.0812743883615744119718922}};

    static const storedGL<9> Order9 = {{-0.9739065285171717200779640, -0.8650633666889845107320967,
                           -0.6794095682990244062343274, -0.4333953941292471907992659,
                           -0.1488743389816312108848260, 0.1488743389816312108848260,
                           0.4333953941292471907992659, 0.6794095682990244062343274,
                           0.8650633666889845107320967, 0.9739065285171717200779640},

                          {0.0666713443086881375935688, 0.1494513491505805931457763,
                                  0.2190863625159820439955349, 0.2692667193099963550912269,
                                  0.2955242247147528701738930, 0.2955242247147528701738930,
                                  0.2692667193099963550912269, 0.2190863625159820439955349,
                                  0.1494513491505805931457763, 0.0666713443086881375935688}};

    static const storedGL<10> Order10 = {{-0.9782286581460569928039380, -0.8870625997680952990751578,
                             -0.7301520055740493240934163, -0.5190961292068118159257257,
                                    -0.2695431559523449723315320, 0, 0.2695431559523449723315320,
                                    0.5190961292068118159257257, 0.7301520055740493240934163,
                                    0.8870625997680952990751578, 0.9782286581460569928039380},

                           {0.0556685671161736664827537, 0.1255803694649046246346943,
                                   0.1862902109277342514260976, 0.2331937645919904799185237,
                                   0.2628045445102466621806889, 0.2729250867779006307144835,
                                   0.2628045445102466621806889, 0.2331937645919904799185237,
                                   0.1862902109277342514260976, 0.1255803694649046246346943,
                                   0.0556685671161736664827537}};

    static const std::tuple<storedGL<1>, storedGL<2>, storedGL<3>, storedGL<4>, storedGL<5>, storedGL<6>,
    storedGL<7>, storedGL<8>, storedGL<9>, storedGL<10>> storedOrders =
            std::make_tuple(Order1, Order2, Order3, Order4, Order5, Order6, Order7, Order8, Order9, Order10);


template<size_t N>
storedGL<N> GaussLegendre()
{
    return std::get<N - 1>(storedOrders);
}
