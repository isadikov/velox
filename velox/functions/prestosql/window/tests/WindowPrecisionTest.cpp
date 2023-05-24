/*
* Copyright (c) Facebook, Inc. and its affiliates.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "velox/functions/prestosql/window/tests/WindowTestBase.h"

using namespace facebook::velox::exec::test;

namespace facebook::velox::window::test {

namespace {

class WindowPrecisionTest : public WindowTestBase {
public:
 std::vector<RowVectorPtr> getData() {
   return {
     makeRowVector(
         {"c0", "s0", "s1", "s2"},
         {
             makeNullableFlatVector<double>({0.5087704409379512, 0.07948068692348897, 0.7637821321841329, 0.7766568271908909, std::nullopt, 0.6263267535250634, 0.5648134578950703, std::nullopt, 0.1644097191747278, std::nullopt, 0.34733827342279255, 0.7297698252368718, 0.8648159704171121, std::nullopt, 0.47001087106764317, 0.855230551213026, std::nullopt, 0.6649325070902705, 0.15467647183686495, 0.699723846046254, std::nullopt, 0.01878900662995875, 0.80036989483051, 0.32621448556892574, 0.424363853642717, std::nullopt, 0.027421661419793963, 0.49922171025536954, 0.49684719438664615, 0.34802197688259184, 0.9054335248656571, 0.5342236231081188, 0.8739067558199167, std::nullopt, 0.480662090703845, 0.2807784539181739, 0.034346081083640456, 0.1407986560370773, std::nullopt, 0.9209706347901374, 0.8325781642924994, 0.3428885228931904, 0.6601881214883178, 0.13337951619178057, 0.07730695814825594, std::nullopt, 0.7413492761552334, 0.1845967231784016, 0.054922638926655054, 0.6263267535250634, std::nullopt, 0.4742154888808727, 0.04890521406196058, 0.44076563720591366, std::nullopt, 0.2575527881272137, 0.21530180680565536, 0.21748919785022736, 0.3343369571957737, 0.4604321925435215, 0.2798019202891737, 0.845783636206761, 0.16973093710839748, 0.19445082801394165, 0.9195640974212438, 0.3785670343786478, 0.12033282429911196, 0.7783949587028474, 0.45289523201063275, 0.37735530664213, 0.66009914688766, 0.8573598808143288, 0.030621590791270137, 0.911522553069517, 0.3139360931236297, 0.19884615228511393, 0.5897049910854548, 0.24303400632925332, 0.08438133355230093, 0.4375510953832418, 0.3671591237653047, 0.7660828637890518, 0.10631489544175565, 0.7800736727658659, 0.8664958460722119, 0.5206652509514242, std::nullopt, 0.8985833157785237, 0.7795400100294501, std::nullopt, std::nullopt, 0.6409506623167545, std::nullopt, 0.5064132763072848, 0.11765299690887332, 0.6601428154390305, 0.4396328709553927, 0.4993241566698998, std::nullopt, std::nullopt, 0.231342839775607, 0.5324182931799442, 0.7665763110853732, 0.6034012010786682, std::nullopt, std::nullopt, 0.13665081514045596, 0.9461494276765734, std::nullopt, 0.7531548347324133, 0.8269880511797965, 0.9671743146609515, 0.26593017601408064, 0.8711159313097596, 0.3088597785681486, 0.07957473141141236, 0.01540788821876049, std::nullopt, 0.13248913898132741, std::nullopt, 0.8959761050064117, 0.42427731095813215, 0.7919615518767387, 0.8745603347197175, 0.08426882466301322, std::nullopt, 0.886845022905618, 0.7175111607648432, 0.28938315249979496}),
             makeNullableFlatVector<int32_t>({113, 326, 354, 584, 879, 1457, 1630, 2032, 2430, 2494, 2521, 2587, 3181, 3509, 3723, 3733, 3858, 3858, 3858, 4091, 5098, 5252, 5895, 6094, 6133, 6877, 6877, 7110, 7240, 7254, 7375, 7491, 7502, 7557, 7649, 7654, 7744, 7754, 7810, 7896, 7971, 8038, 8575, 9299, 9942, 10003, 10026, 10113, 11070, 11634, 11677, 11836, 13980, 16280, 16688, 16723, 17378, 17455, 17682, 17701, 17834, 17989, 18005, 18207, 18678, 18797, 19052, 19055, 19351, 19874, 19964, 20017, 20113, 20352, 20539, 20762, 21276, 21975, 22192, 22195, 22728, 22819, 23056, 23844, 24257, 24539, 24601, 24728, 24882, 24974, 24974, 25353, 25529, 25939, 26813, 26892, 26940, 27112, 27146, 27412, 27551, 27582, 27626, 27723, 27792, 28562, 29054, 29468, 29859, 30098, 30116, 30197, 30563, 30876, 31632, 31759, 31784, 31973, 32182, 32321, 32644, 32743, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt}),
             makeNullableFlatVector<int32_t>({std::nullopt, 106, 7, 88, 82, std::nullopt, 54, 71, std::nullopt, std::nullopt, std::nullopt, 38, 112, 104, 13, 127, 30, 41, 97, 30, 21, 14, 0, 26, 72, 22, 74, 45, std::nullopt, std::nullopt, 85, 123, 83, 41, 71, 82, 64, std::nullopt, 21, 82, 76, std::nullopt, std::nullopt, 100, 102, 33, 2, 119, 73, std::nullopt, std::nullopt, 12, 125, 107, 80, 82, 7, std::nullopt, std::nullopt, 127, std::nullopt, 0, 34, 50, std::nullopt, 26, std::nullopt, std::nullopt, 82, 84, 50, std::nullopt, 30, std::nullopt, 11, 3, 122, 82, std::nullopt, std::nullopt, std::nullopt, 1, 125, 16, 27, 117, 55, std::nullopt, 82, 76, 106, std::nullopt, std::nullopt, 0, 54, std::nullopt, 34, 58, 82, 125, 20, std::nullopt, 59, std::nullopt, 76, 2, std::nullopt, 119, 4, 44, 82, 121, 96, 105, 104, 47, std::nullopt, 70, 63, 102, 22, std::nullopt, 27, 39, 48, 63, 72, 82, 82}),
             makeNullableFlatVector<int32_t>({114, 119, 31, 106, 22, 124, 118, 63, 32, 32, std::nullopt, 110, 18, 89, 25, 13, 110, 48, 83, 13, 65, 90, 25, 42, std::nullopt, 120, 9, std::nullopt, 95, 105, 79, 43, 56, 50, 114, std::nullopt, 46, 23, 73, 124, std::nullopt, 32, 73, 8, 36, 111, std::nullopt, 9, 73, 88, 56, 127, 12, std::nullopt, std::nullopt, 120, 111, 89, 89, 73, std::nullopt, std::nullopt, std::nullopt, 47, std::nullopt, std::nullopt, 1, 44, 64, 52, 25, 80, 84, 49, 103, 115, 14, 65, 44, std::nullopt, 94, 89, 0, 14, 100, 89, 67, 26, 33, 100, 127, std::nullopt, 99, 70, 37, 110, 19, std::nullopt, 20, 34, 104, 84, std::nullopt, 123, 123, 89, 23, 108, 126, std::nullopt, 56, 58, std::nullopt, 105, std::nullopt, 68, 107, std::nullopt, 89, std::nullopt, 33, 66, 17, 39, 47, std::nullopt, 89, 41, 114}),
         }),
   };
 }
};

TEST_F(WindowPrecisionTest, repro) {
 auto input = getData();
 testWindowFunction(input, "avg(c0)", {"order by s0 ASC NULLS LAST, s1 ASC NULLS LAST, s2 ASC NULLS LAST"});
}

}; // namespace
}; // namespace facebook::velox::window::test
