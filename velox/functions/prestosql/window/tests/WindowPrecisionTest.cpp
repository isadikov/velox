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
             makeNullableFlatVector<double>({0.5087704409379512, 0.9209706347901374, 0.28938315249979496, std::nullopt, 0.7175111607648432, 0.2807784539181739, std::nullopt, 0.8269880511797965, 0.2575527881272137, 0.45289523201063275, 0.7795400100294501, 0.07948068692348897, 0.3088597785681486, 0.32621448556892574, 0.4742154888808727, 0.49922171025536954, std::nullopt, 0.030621590791270137, 0.19884615228511393, 0.04890521406196058, 0.5648134578950703, 0.231342839775607, 0.5897049910854548, 0.8745603347197175, std::nullopt, 0.37735530664213, 0.9054335248656571, 0.21530180680565536, std::nullopt, 0.5064132763072848, std::nullopt, std::nullopt, std::nullopt, 0.01878900662995875, 0.7800736727658659, 0.8711159313097596, 0.8648159704171121, 0.699723846046254, 0.8325781642924994, 0.49684719438664615, 0.5206652509514242, std::nullopt, 0.9195640974212438, 0.11765299690887332, 0.12033282429911196, 0.10631489544175565, 0.3199373623356223, 0.07881340803578496, 0.1407986560370773, 0.5324182931799442, 0.42427731095813215, 0.8739067558199167, 0.27100510126911104, 0.13665081514045596, std::nullopt, 0.4396328709553927, 0.66009914688766, 0.7660828637890518, 0.4604321925435215, 0.5342236231081188, std::nullopt, 0.2798019202891737, 0.08438133355230093, 0.7297698252368718, 0.424363853642717, 0.7766568271908909, 0.9671743146609515, 0.054922638926655054, 0.47001087106764317, 0.3343369571957737, 0.7413492761552334, 0.21748919785022736, 0.3785670343786478, 0.845783636206761, 0.80036989483051, 0.16973093710839748, 0.24303400632925332, 0.1845967231784016, std::nullopt, std::nullopt, 0.911522553069517, 0.7531548347324133, 0.7665763110853732, 0.8959761050064117, 0.855230551213026, 0.26593017601408064, 0.6601428154390305, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 0.7637821321841329, 0.6034012010786682, 0.1644097191747278, 0.8985833157785237, 0.3428885228931904, 0.01540788821876049, 0.6263267535250634, std::nullopt, 0.6409506623167545, 0.4375510953832418, 0.34802197688259184, 0.7783949587028474, 0.6263267535250634, 0.3671591237653047, 0.34733827342279255, 0.6601881214883178, std::nullopt, std::nullopt, 0.8573598808143288, std::nullopt, 0.44076563720591366, 0.6649325070902705, 0.13337951619178057, 0.6097438766155392, 0.8000348485074937, std::nullopt, 0.9461494276765734, std::nullopt, 0.034346081083640456, 0.3139360931236297, 0.07957473141141236, 0.08426882466301322, 0.3497768153902143, 0.886845022905618, 0.6664308093022555, 0.8664958460722119, 0.027421661419793963, std::nullopt, 0.07730695814825594, std::nullopt, 0.7919615518767387, 0.480662090703845, 0.19445082801394165, 0.4993241566698998, 0.15467647183686495, 0.13248913898132741}),
             makeNullableFlatVector<int32_t>({113, 7896, std::nullopt, 27146, std::nullopt, 7654, 879, 30116, 16723, 19351, 24882, 326, 31632, 6094, 11836, 7110, 7810, 20113, 20762, 13980, 1630, 27551, 21276, std::nullopt, 2032, 19874, 7375, 17378, 27792, 25939, 24601, 10003, std::nullopt, 5252, 23844, 30876, 3181, 4091, 7971, 7240, 24539, 27412, 18678, 26813, 19052, 23056, std::nullopt, std::nullopt, 7754, 27582, 32743, 7502, std::nullopt, 29054, 31973, 26940, 19964, 22819, 17701, 7491, 3509, 17834, 22192, 2587, 6133, 584, 30197, 11070, 3723, 17682, 10026, 17455, 18797, 17989, 5895, 18005, 21975, 10113, 5098, 28562, 20352, 30098, 27626, 32644, 3733, 30563, 26892, 24974, 24974, 11677, 32321, 354, 27723, 2430, 24728, 8038, 31784, 1457, 2494, 25353, 22195, 7254, 19055, 11634, 22728, 2521, 8575, 25529, std::nullopt, 20017, 16688, 16280, 3858, 9299, std::nullopt, std::nullopt, 7557, 29468, 6877, 7744, 20539, 31759, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 24257, 6877, 29859, 9942, 3858, std::nullopt, 7649, 18207, 27112, 3858, 32182}),
             makeNullableFlatVector<int32_t>({std::nullopt, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 106, 104, 26, 12, 45, 21, 30, 3, 125, 54, 20, 122, 39, 71, 84, 85, 7, 76, 0, 55, 33, 63, 14, 16, 105, 112, 30, 76, std::nullopt, 117, 125, std::nullopt, 54, std::nullopt, 125, 83, 83, std::nullopt, std::nullopt, std::nullopt, 83, std::nullopt, std::nullopt, 70, 34, 50, 1, 127, 123, 104, std::nullopt, std::nullopt, 38, 72, 88, 121, 73, 13, std::nullopt, 2, std::nullopt, 26, 0, 0, 34, 82, 119, 21, 2, std::nullopt, 44, 59, 22, 127, 96, std::nullopt, 76, 106, std::nullopt, 102, 7, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 80, 107, 41, 100, 91, std::nullopt, 41, 119, 22, 64, 11, 47, 48, std::nullopt, 72, 110, 27, 74, 4, 102, 30, 27, 71, 50, 58, 97, 63}),
             makeNullableFlatVector<int32_t>({114, 124, 114, 20, 41, std::nullopt, 22, 56, 120, 64, 33, 119, std::nullopt, 42, 127, std::nullopt, 73, 84, 115, 12, 118, 104, 14, 39, 63, 52, 79, 111, 123, 70, 67, 111, std::nullopt, 90, 14, 105, 18, 13, std::nullopt, 95, 89, 34, std::nullopt, 37, 1, 0, 16, 70, 23, 84, 66, 56, 92, 23, std::nullopt, 19, 25, 89, 73, 43, 89, std::nullopt, 44, 110, std::nullopt, 106, 58, 73, 25, 89, std::nullopt, 89, std::nullopt, std::nullopt, 25, std::nullopt, 65, 9, 65, 89, 49, std::nullopt, std::nullopt, 33, 13, std::nullopt, 110, 100, 127, 56, std::nullopt, 31, 123, 32, 26, 32, 107, 124, 32, std::nullopt, std::nullopt, 105, 44, 88, 94, std::nullopt, 73, 99, 83, 80, std::nullopt, std::nullopt, 48, 8, 17, std::nullopt, 50, 108, 120, 46, 103, 68, 47, 71, 89, 116, 100, 9, 126, 36, 110, 17, 114, 47, std::nullopt, 83, 89}),
         }
         ),
   };
 }
};

TEST_F(WindowPrecisionTest, repro) {
 auto input = getData();
 testWindowFunction(input, "avg(c0)", {"order by s0 ASC NULLS LAST, s1 ASC NULLS LAST, s2 ASC NULLS LAST"});
}

}; // namespace
}; // namespace facebook::velox::window::test
