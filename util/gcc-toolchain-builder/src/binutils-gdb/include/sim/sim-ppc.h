/* sim-ppc.h --- interface between PowerPC simulator and GDB.

   Copyright (C) 2004-2023 Free Software Foundation, Inc.

   Contributed by Red Hat.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#if !defined (SIM_PPC_H)
#define SIM_PPC_H

#ifdef __cplusplus
extern "C" {
#endif

/* The register access functions, sim_fetch_register and
   sim_store_register, use the following numbering for PowerPC
   registers.  */

enum sim_ppc_regnum
  {
    /* General-purpose registers, r0 -- r31.  */
    sim_ppc_r0_regnum,
    sim_ppc_r1_regnum,
    sim_ppc_r2_regnum,
    sim_ppc_r3_regnum,
    sim_ppc_r4_regnum,
    sim_ppc_r5_regnum,
    sim_ppc_r6_regnum,
    sim_ppc_r7_regnum,
    sim_ppc_r8_regnum,
    sim_ppc_r9_regnum,
    sim_ppc_r10_regnum,
    sim_ppc_r11_regnum,
    sim_ppc_r12_regnum,
    sim_ppc_r13_regnum,
    sim_ppc_r14_regnum,
    sim_ppc_r15_regnum,
    sim_ppc_r16_regnum,
    sim_ppc_r17_regnum,
    sim_ppc_r18_regnum,
    sim_ppc_r19_regnum,
    sim_ppc_r20_regnum,
    sim_ppc_r21_regnum,
    sim_ppc_r22_regnum,
    sim_ppc_r23_regnum,
    sim_ppc_r24_regnum,
    sim_ppc_r25_regnum,
    sim_ppc_r26_regnum,
    sim_ppc_r27_regnum,
    sim_ppc_r28_regnum,
    sim_ppc_r29_regnum,
    sim_ppc_r30_regnum,
    sim_ppc_r31_regnum,

    /* Floating-point registers, f0 -- f31.  */
    sim_ppc_f0_regnum,
    sim_ppc_f1_regnum,
    sim_ppc_f2_regnum,
    sim_ppc_f3_regnum,
    sim_ppc_f4_regnum,
    sim_ppc_f5_regnum,
    sim_ppc_f6_regnum,
    sim_ppc_f7_regnum,
    sim_ppc_f8_regnum,
    sim_ppc_f9_regnum,
    sim_ppc_f10_regnum,
    sim_ppc_f11_regnum,
    sim_ppc_f12_regnum,
    sim_ppc_f13_regnum,
    sim_ppc_f14_regnum,
    sim_ppc_f15_regnum,
    sim_ppc_f16_regnum,
    sim_ppc_f17_regnum,
    sim_ppc_f18_regnum,
    sim_ppc_f19_regnum,
    sim_ppc_f20_regnum,
    sim_ppc_f21_regnum,
    sim_ppc_f22_regnum,
    sim_ppc_f23_regnum,
    sim_ppc_f24_regnum,
    sim_ppc_f25_regnum,
    sim_ppc_f26_regnum,
    sim_ppc_f27_regnum,
    sim_ppc_f28_regnum,
    sim_ppc_f29_regnum,
    sim_ppc_f30_regnum,
    sim_ppc_f31_regnum,

    /* Altivec vector registers, vr0 -- vr31.  */
    sim_ppc_vr0_regnum,
    sim_ppc_vr1_regnum,
    sim_ppc_vr2_regnum,
    sim_ppc_vr3_regnum,
    sim_ppc_vr4_regnum,
    sim_ppc_vr5_regnum,
    sim_ppc_vr6_regnum,
    sim_ppc_vr7_regnum,
    sim_ppc_vr8_regnum,
    sim_ppc_vr9_regnum,
    sim_ppc_vr10_regnum,
    sim_ppc_vr11_regnum,
    sim_ppc_vr12_regnum,
    sim_ppc_vr13_regnum,
    sim_ppc_vr14_regnum,
    sim_ppc_vr15_regnum,
    sim_ppc_vr16_regnum,
    sim_ppc_vr17_regnum,
    sim_ppc_vr18_regnum,
    sim_ppc_vr19_regnum,
    sim_ppc_vr20_regnum,
    sim_ppc_vr21_regnum,
    sim_ppc_vr22_regnum,
    sim_ppc_vr23_regnum,
    sim_ppc_vr24_regnum,
    sim_ppc_vr25_regnum,
    sim_ppc_vr26_regnum,
    sim_ppc_vr27_regnum,
    sim_ppc_vr28_regnum,
    sim_ppc_vr29_regnum,
    sim_ppc_vr30_regnum,
    sim_ppc_vr31_regnum,

    /* SPE APU GPR upper halves.  These are the upper 32 bits of the
       gprs; there is one upper-half register for each gpr, so it is
       appropriate to use sim_ppc_num_gprs for iterating through
       these.  */
    sim_ppc_rh0_regnum,
    sim_ppc_rh1_regnum,
    sim_ppc_rh2_regnum,
    sim_ppc_rh3_regnum,
    sim_ppc_rh4_regnum,
    sim_ppc_rh5_regnum,
    sim_ppc_rh6_regnum,
    sim_ppc_rh7_regnum,
    sim_ppc_rh8_regnum,
    sim_ppc_rh9_regnum,
    sim_ppc_rh10_regnum,
    sim_ppc_rh11_regnum,
    sim_ppc_rh12_regnum,
    sim_ppc_rh13_regnum,
    sim_ppc_rh14_regnum,
    sim_ppc_rh15_regnum,
    sim_ppc_rh16_regnum,
    sim_ppc_rh17_regnum,
    sim_ppc_rh18_regnum,
    sim_ppc_rh19_regnum,
    sim_ppc_rh20_regnum,
    sim_ppc_rh21_regnum,
    sim_ppc_rh22_regnum,
    sim_ppc_rh23_regnum,
    sim_ppc_rh24_regnum,
    sim_ppc_rh25_regnum,
    sim_ppc_rh26_regnum,
    sim_ppc_rh27_regnum,
    sim_ppc_rh28_regnum,
    sim_ppc_rh29_regnum,
    sim_ppc_rh30_regnum,
    sim_ppc_rh31_regnum,

    /* SPE APU GPR full registers.  Each of these registers is the
       64-bit concatenation of a 32-bit GPR (providing the lower bits)
       and a 32-bit upper-half register (providing the higher bits).
       As for the upper-half registers, it is appropriate to use
       sim_ppc_num_gprs with these.  */
    sim_ppc_ev0_regnum,
    sim_ppc_ev1_regnum,
    sim_ppc_ev2_regnum,
    sim_ppc_ev3_regnum,
    sim_ppc_ev4_regnum,
    sim_ppc_ev5_regnum,
    sim_ppc_ev6_regnum,
    sim_ppc_ev7_regnum,
    sim_ppc_ev8_regnum,
    sim_ppc_ev9_regnum,
    sim_ppc_ev10_regnum,
    sim_ppc_ev11_regnum,
    sim_ppc_ev12_regnum,
    sim_ppc_ev13_regnum,
    sim_ppc_ev14_regnum,
    sim_ppc_ev15_regnum,
    sim_ppc_ev16_regnum,
    sim_ppc_ev17_regnum,
    sim_ppc_ev18_regnum,
    sim_ppc_ev19_regnum,
    sim_ppc_ev20_regnum,
    sim_ppc_ev21_regnum,
    sim_ppc_ev22_regnum,
    sim_ppc_ev23_regnum,
    sim_ppc_ev24_regnum,
    sim_ppc_ev25_regnum,
    sim_ppc_ev26_regnum,
    sim_ppc_ev27_regnum,
    sim_ppc_ev28_regnum,
    sim_ppc_ev29_regnum,
    sim_ppc_ev30_regnum,
    sim_ppc_ev31_regnum,

    /* Segment registers, sr0 -- sr15.  */
    sim_ppc_sr0_regnum,
    sim_ppc_sr1_regnum,
    sim_ppc_sr2_regnum,
    sim_ppc_sr3_regnum,
    sim_ppc_sr4_regnum,
    sim_ppc_sr5_regnum,
    sim_ppc_sr6_regnum,
    sim_ppc_sr7_regnum,
    sim_ppc_sr8_regnum,
    sim_ppc_sr9_regnum,
    sim_ppc_sr10_regnum,
    sim_ppc_sr11_regnum,
    sim_ppc_sr12_regnum,
    sim_ppc_sr13_regnum,
    sim_ppc_sr14_regnum,
    sim_ppc_sr15_regnum,

    /* Miscellaneous --- but non-SPR --- registers.  */
    sim_ppc_pc_regnum,
    sim_ppc_ps_regnum,
    sim_ppc_cr_regnum,
    sim_ppc_fpscr_regnum,
    sim_ppc_acc_regnum,
    sim_ppc_vscr_regnum,

    /* Special-purpose registers.  */
    sim_ppc_spr0_regnum, sim_ppc_spr1_regnum,
    sim_ppc_spr2_regnum, sim_ppc_spr3_regnum,
    sim_ppc_spr4_regnum, sim_ppc_spr5_regnum,
    sim_ppc_spr6_regnum, sim_ppc_spr7_regnum,
    sim_ppc_spr8_regnum, sim_ppc_spr9_regnum,
    sim_ppc_spr10_regnum, sim_ppc_spr11_regnum,
    sim_ppc_spr12_regnum, sim_ppc_spr13_regnum,
    sim_ppc_spr14_regnum, sim_ppc_spr15_regnum,
    sim_ppc_spr16_regnum, sim_ppc_spr17_regnum,
    sim_ppc_spr18_regnum, sim_ppc_spr19_regnum,
    sim_ppc_spr20_regnum, sim_ppc_spr21_regnum,
    sim_ppc_spr22_regnum, sim_ppc_spr23_regnum,
    sim_ppc_spr24_regnum, sim_ppc_spr25_regnum,
    sim_ppc_spr26_regnum, sim_ppc_spr27_regnum,
    sim_ppc_spr28_regnum, sim_ppc_spr29_regnum,
    sim_ppc_spr30_regnum, sim_ppc_spr31_regnum,
    sim_ppc_spr32_regnum, sim_ppc_spr33_regnum,
    sim_ppc_spr34_regnum, sim_ppc_spr35_regnum,
    sim_ppc_spr36_regnum, sim_ppc_spr37_regnum,
    sim_ppc_spr38_regnum, sim_ppc_spr39_regnum,
    sim_ppc_spr40_regnum, sim_ppc_spr41_regnum,
    sim_ppc_spr42_regnum, sim_ppc_spr43_regnum,
    sim_ppc_spr44_regnum, sim_ppc_spr45_regnum,
    sim_ppc_spr46_regnum, sim_ppc_spr47_regnum,
    sim_ppc_spr48_regnum, sim_ppc_spr49_regnum,
    sim_ppc_spr50_regnum, sim_ppc_spr51_regnum,
    sim_ppc_spr52_regnum, sim_ppc_spr53_regnum,
    sim_ppc_spr54_regnum, sim_ppc_spr55_regnum,
    sim_ppc_spr56_regnum, sim_ppc_spr57_regnum,
    sim_ppc_spr58_regnum, sim_ppc_spr59_regnum,
    sim_ppc_spr60_regnum, sim_ppc_spr61_regnum,
    sim_ppc_spr62_regnum, sim_ppc_spr63_regnum,
    sim_ppc_spr64_regnum, sim_ppc_spr65_regnum,
    sim_ppc_spr66_regnum, sim_ppc_spr67_regnum,
    sim_ppc_spr68_regnum, sim_ppc_spr69_regnum,
    sim_ppc_spr70_regnum, sim_ppc_spr71_regnum,
    sim_ppc_spr72_regnum, sim_ppc_spr73_regnum,
    sim_ppc_spr74_regnum, sim_ppc_spr75_regnum,
    sim_ppc_spr76_regnum, sim_ppc_spr77_regnum,
    sim_ppc_spr78_regnum, sim_ppc_spr79_regnum,
    sim_ppc_spr80_regnum, sim_ppc_spr81_regnum,
    sim_ppc_spr82_regnum, sim_ppc_spr83_regnum,
    sim_ppc_spr84_regnum, sim_ppc_spr85_regnum,
    sim_ppc_spr86_regnum, sim_ppc_spr87_regnum,
    sim_ppc_spr88_regnum, sim_ppc_spr89_regnum,
    sim_ppc_spr90_regnum, sim_ppc_spr91_regnum,
    sim_ppc_spr92_regnum, sim_ppc_spr93_regnum,
    sim_ppc_spr94_regnum, sim_ppc_spr95_regnum,
    sim_ppc_spr96_regnum, sim_ppc_spr97_regnum,
    sim_ppc_spr98_regnum, sim_ppc_spr99_regnum,
    sim_ppc_spr100_regnum, sim_ppc_spr101_regnum,
    sim_ppc_spr102_regnum, sim_ppc_spr103_regnum,
    sim_ppc_spr104_regnum, sim_ppc_spr105_regnum,
    sim_ppc_spr106_regnum, sim_ppc_spr107_regnum,
    sim_ppc_spr108_regnum, sim_ppc_spr109_regnum,
    sim_ppc_spr110_regnum, sim_ppc_spr111_regnum,
    sim_ppc_spr112_regnum, sim_ppc_spr113_regnum,
    sim_ppc_spr114_regnum, sim_ppc_spr115_regnum,
    sim_ppc_spr116_regnum, sim_ppc_spr117_regnum,
    sim_ppc_spr118_regnum, sim_ppc_spr119_regnum,
    sim_ppc_spr120_regnum, sim_ppc_spr121_regnum,
    sim_ppc_spr122_regnum, sim_ppc_spr123_regnum,
    sim_ppc_spr124_regnum, sim_ppc_spr125_regnum,
    sim_ppc_spr126_regnum, sim_ppc_spr127_regnum,
    sim_ppc_spr128_regnum, sim_ppc_spr129_regnum,
    sim_ppc_spr130_regnum, sim_ppc_spr131_regnum,
    sim_ppc_spr132_regnum, sim_ppc_spr133_regnum,
    sim_ppc_spr134_regnum, sim_ppc_spr135_regnum,
    sim_ppc_spr136_regnum, sim_ppc_spr137_regnum,
    sim_ppc_spr138_regnum, sim_ppc_spr139_regnum,
    sim_ppc_spr140_regnum, sim_ppc_spr141_regnum,
    sim_ppc_spr142_regnum, sim_ppc_spr143_regnum,
    sim_ppc_spr144_regnum, sim_ppc_spr145_regnum,
    sim_ppc_spr146_regnum, sim_ppc_spr147_regnum,
    sim_ppc_spr148_regnum, sim_ppc_spr149_regnum,
    sim_ppc_spr150_regnum, sim_ppc_spr151_regnum,
    sim_ppc_spr152_regnum, sim_ppc_spr153_regnum,
    sim_ppc_spr154_regnum, sim_ppc_spr155_regnum,
    sim_ppc_spr156_regnum, sim_ppc_spr157_regnum,
    sim_ppc_spr158_regnum, sim_ppc_spr159_regnum,
    sim_ppc_spr160_regnum, sim_ppc_spr161_regnum,
    sim_ppc_spr162_regnum, sim_ppc_spr163_regnum,
    sim_ppc_spr164_regnum, sim_ppc_spr165_regnum,
    sim_ppc_spr166_regnum, sim_ppc_spr167_regnum,
    sim_ppc_spr168_regnum, sim_ppc_spr169_regnum,
    sim_ppc_spr170_regnum, sim_ppc_spr171_regnum,
    sim_ppc_spr172_regnum, sim_ppc_spr173_regnum,
    sim_ppc_spr174_regnum, sim_ppc_spr175_regnum,
    sim_ppc_spr176_regnum, sim_ppc_spr177_regnum,
    sim_ppc_spr178_regnum, sim_ppc_spr179_regnum,
    sim_ppc_spr180_regnum, sim_ppc_spr181_regnum,
    sim_ppc_spr182_regnum, sim_ppc_spr183_regnum,
    sim_ppc_spr184_regnum, sim_ppc_spr185_regnum,
    sim_ppc_spr186_regnum, sim_ppc_spr187_regnum,
    sim_ppc_spr188_regnum, sim_ppc_spr189_regnum,
    sim_ppc_spr190_regnum, sim_ppc_spr191_regnum,
    sim_ppc_spr192_regnum, sim_ppc_spr193_regnum,
    sim_ppc_spr194_regnum, sim_ppc_spr195_regnum,
    sim_ppc_spr196_regnum, sim_ppc_spr197_regnum,
    sim_ppc_spr198_regnum, sim_ppc_spr199_regnum,
    sim_ppc_spr200_regnum, sim_ppc_spr201_regnum,
    sim_ppc_spr202_regnum, sim_ppc_spr203_regnum,
    sim_ppc_spr204_regnum, sim_ppc_spr205_regnum,
    sim_ppc_spr206_regnum, sim_ppc_spr207_regnum,
    sim_ppc_spr208_regnum, sim_ppc_spr209_regnum,
    sim_ppc_spr210_regnum, sim_ppc_spr211_regnum,
    sim_ppc_spr212_regnum, sim_ppc_spr213_regnum,
    sim_ppc_spr214_regnum, sim_ppc_spr215_regnum,
    sim_ppc_spr216_regnum, sim_ppc_spr217_regnum,
    sim_ppc_spr218_regnum, sim_ppc_spr219_regnum,
    sim_ppc_spr220_regnum, sim_ppc_spr221_regnum,
    sim_ppc_spr222_regnum, sim_ppc_spr223_regnum,
    sim_ppc_spr224_regnum, sim_ppc_spr225_regnum,
    sim_ppc_spr226_regnum, sim_ppc_spr227_regnum,
    sim_ppc_spr228_regnum, sim_ppc_spr229_regnum,
    sim_ppc_spr230_regnum, sim_ppc_spr231_regnum,
    sim_ppc_spr232_regnum, sim_ppc_spr233_regnum,
    sim_ppc_spr234_regnum, sim_ppc_spr235_regnum,
    sim_ppc_spr236_regnum, sim_ppc_spr237_regnum,
    sim_ppc_spr238_regnum, sim_ppc_spr239_regnum,
    sim_ppc_spr240_regnum, sim_ppc_spr241_regnum,
    sim_ppc_spr242_regnum, sim_ppc_spr243_regnum,
    sim_ppc_spr244_regnum, sim_ppc_spr245_regnum,
    sim_ppc_spr246_regnum, sim_ppc_spr247_regnum,
    sim_ppc_spr248_regnum, sim_ppc_spr249_regnum,
    sim_ppc_spr250_regnum, sim_ppc_spr251_regnum,
    sim_ppc_spr252_regnum, sim_ppc_spr253_regnum,
    sim_ppc_spr254_regnum, sim_ppc_spr255_regnum,
    sim_ppc_spr256_regnum, sim_ppc_spr257_regnum,
    sim_ppc_spr258_regnum, sim_ppc_spr259_regnum,
    sim_ppc_spr260_regnum, sim_ppc_spr261_regnum,
    sim_ppc_spr262_regnum, sim_ppc_spr263_regnum,
    sim_ppc_spr264_regnum, sim_ppc_spr265_regnum,
    sim_ppc_spr266_regnum, sim_ppc_spr267_regnum,
    sim_ppc_spr268_regnum, sim_ppc_spr269_regnum,
    sim_ppc_spr270_regnum, sim_ppc_spr271_regnum,
    sim_ppc_spr272_regnum, sim_ppc_spr273_regnum,
    sim_ppc_spr274_regnum, sim_ppc_spr275_regnum,
    sim_ppc_spr276_regnum, sim_ppc_spr277_regnum,
    sim_ppc_spr278_regnum, sim_ppc_spr279_regnum,
    sim_ppc_spr280_regnum, sim_ppc_spr281_regnum,
    sim_ppc_spr282_regnum, sim_ppc_spr283_regnum,
    sim_ppc_spr284_regnum, sim_ppc_spr285_regnum,
    sim_ppc_spr286_regnum, sim_ppc_spr287_regnum,
    sim_ppc_spr288_regnum, sim_ppc_spr289_regnum,
    sim_ppc_spr290_regnum, sim_ppc_spr291_regnum,
    sim_ppc_spr292_regnum, sim_ppc_spr293_regnum,
    sim_ppc_spr294_regnum, sim_ppc_spr295_regnum,
    sim_ppc_spr296_regnum, sim_ppc_spr297_regnum,
    sim_ppc_spr298_regnum, sim_ppc_spr299_regnum,
    sim_ppc_spr300_regnum, sim_ppc_spr301_regnum,
    sim_ppc_spr302_regnum, sim_ppc_spr303_regnum,
    sim_ppc_spr304_regnum, sim_ppc_spr305_regnum,
    sim_ppc_spr306_regnum, sim_ppc_spr307_regnum,
    sim_ppc_spr308_regnum, sim_ppc_spr309_regnum,
    sim_ppc_spr310_regnum, sim_ppc_spr311_regnum,
    sim_ppc_spr312_regnum, sim_ppc_spr313_regnum,
    sim_ppc_spr314_regnum, sim_ppc_spr315_regnum,
    sim_ppc_spr316_regnum, sim_ppc_spr317_regnum,
    sim_ppc_spr318_regnum, sim_ppc_spr319_regnum,
    sim_ppc_spr320_regnum, sim_ppc_spr321_regnum,
    sim_ppc_spr322_regnum, sim_ppc_spr323_regnum,
    sim_ppc_spr324_regnum, sim_ppc_spr325_regnum,
    sim_ppc_spr326_regnum, sim_ppc_spr327_regnum,
    sim_ppc_spr328_regnum, sim_ppc_spr329_regnum,
    sim_ppc_spr330_regnum, sim_ppc_spr331_regnum,
    sim_ppc_spr332_regnum, sim_ppc_spr333_regnum,
    sim_ppc_spr334_regnum, sim_ppc_spr335_regnum,
    sim_ppc_spr336_regnum, sim_ppc_spr337_regnum,
    sim_ppc_spr338_regnum, sim_ppc_spr339_regnum,
    sim_ppc_spr340_regnum, sim_ppc_spr341_regnum,
    sim_ppc_spr342_regnum, sim_ppc_spr343_regnum,
    sim_ppc_spr344_regnum, sim_ppc_spr345_regnum,
    sim_ppc_spr346_regnum, sim_ppc_spr347_regnum,
    sim_ppc_spr348_regnum, sim_ppc_spr349_regnum,
    sim_ppc_spr350_regnum, sim_ppc_spr351_regnum,
    sim_ppc_spr352_regnum, sim_ppc_spr353_regnum,
    sim_ppc_spr354_regnum, sim_ppc_spr355_regnum,
    sim_ppc_spr356_regnum, sim_ppc_spr357_regnum,
    sim_ppc_spr358_regnum, sim_ppc_spr359_regnum,
    sim_ppc_spr360_regnum, sim_ppc_spr361_regnum,
    sim_ppc_spr362_regnum, sim_ppc_spr363_regnum,
    sim_ppc_spr364_regnum, sim_ppc_spr365_regnum,
    sim_ppc_spr366_regnum, sim_ppc_spr367_regnum,
    sim_ppc_spr368_regnum, sim_ppc_spr369_regnum,
    sim_ppc_spr370_regnum, sim_ppc_spr371_regnum,
    sim_ppc_spr372_regnum, sim_ppc_spr373_regnum,
    sim_ppc_spr374_regnum, sim_ppc_spr375_regnum,
    sim_ppc_spr376_regnum, sim_ppc_spr377_regnum,
    sim_ppc_spr378_regnum, sim_ppc_spr379_regnum,
    sim_ppc_spr380_regnum, sim_ppc_spr381_regnum,
    sim_ppc_spr382_regnum, sim_ppc_spr383_regnum,
    sim_ppc_spr384_regnum, sim_ppc_spr385_regnum,
    sim_ppc_spr386_regnum, sim_ppc_spr387_regnum,
    sim_ppc_spr388_regnum, sim_ppc_spr389_regnum,
    sim_ppc_spr390_regnum, sim_ppc_spr391_regnum,
    sim_ppc_spr392_regnum, sim_ppc_spr393_regnum,
    sim_ppc_spr394_regnum, sim_ppc_spr395_regnum,
    sim_ppc_spr396_regnum, sim_ppc_spr397_regnum,
    sim_ppc_spr398_regnum, sim_ppc_spr399_regnum,
    sim_ppc_spr400_regnum, sim_ppc_spr401_regnum,
    sim_ppc_spr402_regnum, sim_ppc_spr403_regnum,
    sim_ppc_spr404_regnum, sim_ppc_spr405_regnum,
    sim_ppc_spr406_regnum, sim_ppc_spr407_regnum,
    sim_ppc_spr408_regnum, sim_ppc_spr409_regnum,
    sim_ppc_spr410_regnum, sim_ppc_spr411_regnum,
    sim_ppc_spr412_regnum, sim_ppc_spr413_regnum,
    sim_ppc_spr414_regnum, sim_ppc_spr415_regnum,
    sim_ppc_spr416_regnum, sim_ppc_spr417_regnum,
    sim_ppc_spr418_regnum, sim_ppc_spr419_regnum,
    sim_ppc_spr420_regnum, sim_ppc_spr421_regnum,
    sim_ppc_spr422_regnum, sim_ppc_spr423_regnum,
    sim_ppc_spr424_regnum, sim_ppc_spr425_regnum,
    sim_ppc_spr426_regnum, sim_ppc_spr427_regnum,
    sim_ppc_spr428_regnum, sim_ppc_spr429_regnum,
    sim_ppc_spr430_regnum, sim_ppc_spr431_regnum,
    sim_ppc_spr432_regnum, sim_ppc_spr433_regnum,
    sim_ppc_spr434_regnum, sim_ppc_spr435_regnum,
    sim_ppc_spr436_regnum, sim_ppc_spr437_regnum,
    sim_ppc_spr438_regnum, sim_ppc_spr439_regnum,
    sim_ppc_spr440_regnum, sim_ppc_spr441_regnum,
    sim_ppc_spr442_regnum, sim_ppc_spr443_regnum,
    sim_ppc_spr444_regnum, sim_ppc_spr445_regnum,
    sim_ppc_spr446_regnum, sim_ppc_spr447_regnum,
    sim_ppc_spr448_regnum, sim_ppc_spr449_regnum,
    sim_ppc_spr450_regnum, sim_ppc_spr451_regnum,
    sim_ppc_spr452_regnum, sim_ppc_spr453_regnum,
    sim_ppc_spr454_regnum, sim_ppc_spr455_regnum,
    sim_ppc_spr456_regnum, sim_ppc_spr457_regnum,
    sim_ppc_spr458_regnum, sim_ppc_spr459_regnum,
    sim_ppc_spr460_regnum, sim_ppc_spr461_regnum,
    sim_ppc_spr462_regnum, sim_ppc_spr463_regnum,
    sim_ppc_spr464_regnum, sim_ppc_spr465_regnum,
    sim_ppc_spr466_regnum, sim_ppc_spr467_regnum,
    sim_ppc_spr468_regnum, sim_ppc_spr469_regnum,
    sim_ppc_spr470_regnum, sim_ppc_spr471_regnum,
    sim_ppc_spr472_regnum, sim_ppc_spr473_regnum,
    sim_ppc_spr474_regnum, sim_ppc_spr475_regnum,
    sim_ppc_spr476_regnum, sim_ppc_spr477_regnum,
    sim_ppc_spr478_regnum, sim_ppc_spr479_regnum,
    sim_ppc_spr480_regnum, sim_ppc_spr481_regnum,
    sim_ppc_spr482_regnum, sim_ppc_spr483_regnum,
    sim_ppc_spr484_regnum, sim_ppc_spr485_regnum,
    sim_ppc_spr486_regnum, sim_ppc_spr487_regnum,
    sim_ppc_spr488_regnum, sim_ppc_spr489_regnum,
    sim_ppc_spr490_regnum, sim_ppc_spr491_regnum,
    sim_ppc_spr492_regnum, sim_ppc_spr493_regnum,
    sim_ppc_spr494_regnum, sim_ppc_spr495_regnum,
    sim_ppc_spr496_regnum, sim_ppc_spr497_regnum,
    sim_ppc_spr498_regnum, sim_ppc_spr499_regnum,
    sim_ppc_spr500_regnum, sim_ppc_spr501_regnum,
    sim_ppc_spr502_regnum, sim_ppc_spr503_regnum,
    sim_ppc_spr504_regnum, sim_ppc_spr505_regnum,
    sim_ppc_spr506_regnum, sim_ppc_spr507_regnum,
    sim_ppc_spr508_regnum, sim_ppc_spr509_regnum,
    sim_ppc_spr510_regnum, sim_ppc_spr511_regnum,
    sim_ppc_spr512_regnum, sim_ppc_spr513_regnum,
    sim_ppc_spr514_regnum, sim_ppc_spr515_regnum,
    sim_ppc_spr516_regnum, sim_ppc_spr517_regnum,
    sim_ppc_spr518_regnum, sim_ppc_spr519_regnum,
    sim_ppc_spr520_regnum, sim_ppc_spr521_regnum,
    sim_ppc_spr522_regnum, sim_ppc_spr523_regnum,
    sim_ppc_spr524_regnum, sim_ppc_spr525_regnum,
    sim_ppc_spr526_regnum, sim_ppc_spr527_regnum,
    sim_ppc_spr528_regnum, sim_ppc_spr529_regnum,
    sim_ppc_spr530_regnum, sim_ppc_spr531_regnum,
    sim_ppc_spr532_regnum, sim_ppc_spr533_regnum,
    sim_ppc_spr534_regnum, sim_ppc_spr535_regnum,
    sim_ppc_spr536_regnum, sim_ppc_spr537_regnum,
    sim_ppc_spr538_regnum, sim_ppc_spr539_regnum,
    sim_ppc_spr540_regnum, sim_ppc_spr541_regnum,
    sim_ppc_spr542_regnum, sim_ppc_spr543_regnum,
    sim_ppc_spr544_regnum, sim_ppc_spr545_regnum,
    sim_ppc_spr546_regnum, sim_ppc_spr547_regnum,
    sim_ppc_spr548_regnum, sim_ppc_spr549_regnum,
    sim_ppc_spr550_regnum, sim_ppc_spr551_regnum,
    sim_ppc_spr552_regnum, sim_ppc_spr553_regnum,
    sim_ppc_spr554_regnum, sim_ppc_spr555_regnum,
    sim_ppc_spr556_regnum, sim_ppc_spr557_regnum,
    sim_ppc_spr558_regnum, sim_ppc_spr559_regnum,
    sim_ppc_spr560_regnum, sim_ppc_spr561_regnum,
    sim_ppc_spr562_regnum, sim_ppc_spr563_regnum,
    sim_ppc_spr564_regnum, sim_ppc_spr565_regnum,
    sim_ppc_spr566_regnum, sim_ppc_spr567_regnum,
    sim_ppc_spr568_regnum, sim_ppc_spr569_regnum,
    sim_ppc_spr570_regnum, sim_ppc_spr571_regnum,
    sim_ppc_spr572_regnum, sim_ppc_spr573_regnum,
    sim_ppc_spr574_regnum, sim_ppc_spr575_regnum,
    sim_ppc_spr576_regnum, sim_ppc_spr577_regnum,
    sim_ppc_spr578_regnum, sim_ppc_spr579_regnum,
    sim_ppc_spr580_regnum, sim_ppc_spr581_regnum,
    sim_ppc_spr582_regnum, sim_ppc_spr583_regnum,
    sim_ppc_spr584_regnum, sim_ppc_spr585_regnum,
    sim_ppc_spr586_regnum, sim_ppc_spr587_regnum,
    sim_ppc_spr588_regnum, sim_ppc_spr589_regnum,
    sim_ppc_spr590_regnum, sim_ppc_spr591_regnum,
    sim_ppc_spr592_regnum, sim_ppc_spr593_regnum,
    sim_ppc_spr594_regnum, sim_ppc_spr595_regnum,
    sim_ppc_spr596_regnum, sim_ppc_spr597_regnum,
    sim_ppc_spr598_regnum, sim_ppc_spr599_regnum,
    sim_ppc_spr600_regnum, sim_ppc_spr601_regnum,
    sim_ppc_spr602_regnum, sim_ppc_spr603_regnum,
    sim_ppc_spr604_regnum, sim_ppc_spr605_regnum,
    sim_ppc_spr606_regnum, sim_ppc_spr607_regnum,
    sim_ppc_spr608_regnum, sim_ppc_spr609_regnum,
    sim_ppc_spr610_regnum, sim_ppc_spr611_regnum,
    sim_ppc_spr612_regnum, sim_ppc_spr613_regnum,
    sim_ppc_spr614_regnum, sim_ppc_spr615_regnum,
    sim_ppc_spr616_regnum, sim_ppc_spr617_regnum,
    sim_ppc_spr618_regnum, sim_ppc_spr619_regnum,
    sim_ppc_spr620_regnum, sim_ppc_spr621_regnum,
    sim_ppc_spr622_regnum, sim_ppc_spr623_regnum,
    sim_ppc_spr624_regnum, sim_ppc_spr625_regnum,
    sim_ppc_spr626_regnum, sim_ppc_spr627_regnum,
    sim_ppc_spr628_regnum, sim_ppc_spr629_regnum,
    sim_ppc_spr630_regnum, sim_ppc_spr631_regnum,
    sim_ppc_spr632_regnum, sim_ppc_spr633_regnum,
    sim_ppc_spr634_regnum, sim_ppc_spr635_regnum,
    sim_ppc_spr636_regnum, sim_ppc_spr637_regnum,
    sim_ppc_spr638_regnum, sim_ppc_spr639_regnum,
    sim_ppc_spr640_regnum, sim_ppc_spr641_regnum,
    sim_ppc_spr642_regnum, sim_ppc_spr643_regnum,
    sim_ppc_spr644_regnum, sim_ppc_spr645_regnum,
    sim_ppc_spr646_regnum, sim_ppc_spr647_regnum,
    sim_ppc_spr648_regnum, sim_ppc_spr649_regnum,
    sim_ppc_spr650_regnum, sim_ppc_spr651_regnum,
    sim_ppc_spr652_regnum, sim_ppc_spr653_regnum,
    sim_ppc_spr654_regnum, sim_ppc_spr655_regnum,
    sim_ppc_spr656_regnum, sim_ppc_spr657_regnum,
    sim_ppc_spr658_regnum, sim_ppc_spr659_regnum,
    sim_ppc_spr660_regnum, sim_ppc_spr661_regnum,
    sim_ppc_spr662_regnum, sim_ppc_spr663_regnum,
    sim_ppc_spr664_regnum, sim_ppc_spr665_regnum,
    sim_ppc_spr666_regnum, sim_ppc_spr667_regnum,
    sim_ppc_spr668_regnum, sim_ppc_spr669_regnum,
    sim_ppc_spr670_regnum, sim_ppc_spr671_regnum,
    sim_ppc_spr672_regnum, sim_ppc_spr673_regnum,
    sim_ppc_spr674_regnum, sim_ppc_spr675_regnum,
    sim_ppc_spr676_regnum, sim_ppc_spr677_regnum,
    sim_ppc_spr678_regnum, sim_ppc_spr679_regnum,
    sim_ppc_spr680_regnum, sim_ppc_spr681_regnum,
    sim_ppc_spr682_regnum, sim_ppc_spr683_regnum,
    sim_ppc_spr684_regnum, sim_ppc_spr685_regnum,
    sim_ppc_spr686_regnum, sim_ppc_spr687_regnum,
    sim_ppc_spr688_regnum, sim_ppc_spr689_regnum,
    sim_ppc_spr690_regnum, sim_ppc_spr691_regnum,
    sim_ppc_spr692_regnum, sim_ppc_spr693_regnum,
    sim_ppc_spr694_regnum, sim_ppc_spr695_regnum,
    sim_ppc_spr696_regnum, sim_ppc_spr697_regnum,
    sim_ppc_spr698_regnum, sim_ppc_spr699_regnum,
    sim_ppc_spr700_regnum, sim_ppc_spr701_regnum,
    sim_ppc_spr702_regnum, sim_ppc_spr703_regnum,
    sim_ppc_spr704_regnum, sim_ppc_spr705_regnum,
    sim_ppc_spr706_regnum, sim_ppc_spr707_regnum,
    sim_ppc_spr708_regnum, sim_ppc_spr709_regnum,
    sim_ppc_spr710_regnum, sim_ppc_spr711_regnum,
    sim_ppc_spr712_regnum, sim_ppc_spr713_regnum,
    sim_ppc_spr714_regnum, sim_ppc_spr715_regnum,
    sim_ppc_spr716_regnum, sim_ppc_spr717_regnum,
    sim_ppc_spr718_regnum, sim_ppc_spr719_regnum,
    sim_ppc_spr720_regnum, sim_ppc_spr721_regnum,
    sim_ppc_spr722_regnum, sim_ppc_spr723_regnum,
    sim_ppc_spr724_regnum, sim_ppc_spr725_regnum,
    sim_ppc_spr726_regnum, sim_ppc_spr727_regnum,
    sim_ppc_spr728_regnum, sim_ppc_spr729_regnum,
    sim_ppc_spr730_regnum, sim_ppc_spr731_regnum,
    sim_ppc_spr732_regnum, sim_ppc_spr733_regnum,
    sim_ppc_spr734_regnum, sim_ppc_spr735_regnum,
    sim_ppc_spr736_regnum, sim_ppc_spr737_regnum,
    sim_ppc_spr738_regnum, sim_ppc_spr739_regnum,
    sim_ppc_spr740_regnum, sim_ppc_spr741_regnum,
    sim_ppc_spr742_regnum, sim_ppc_spr743_regnum,
    sim_ppc_spr744_regnum, sim_ppc_spr745_regnum,
    sim_ppc_spr746_regnum, sim_ppc_spr747_regnum,
    sim_ppc_spr748_regnum, sim_ppc_spr749_regnum,
    sim_ppc_spr750_regnum, sim_ppc_spr751_regnum,
    sim_ppc_spr752_regnum, sim_ppc_spr753_regnum,
    sim_ppc_spr754_regnum, sim_ppc_spr755_regnum,
    sim_ppc_spr756_regnum, sim_ppc_spr757_regnum,
    sim_ppc_spr758_regnum, sim_ppc_spr759_regnum,
    sim_ppc_spr760_regnum, sim_ppc_spr761_regnum,
    sim_ppc_spr762_regnum, sim_ppc_spr763_regnum,
    sim_ppc_spr764_regnum, sim_ppc_spr765_regnum,
    sim_ppc_spr766_regnum, sim_ppc_spr767_regnum,
    sim_ppc_spr768_regnum, sim_ppc_spr769_regnum,
    sim_ppc_spr770_regnum, sim_ppc_spr771_regnum,
    sim_ppc_spr772_regnum, sim_ppc_spr773_regnum,
    sim_ppc_spr774_regnum, sim_ppc_spr775_regnum,
    sim_ppc_spr776_regnum, sim_ppc_spr777_regnum,
    sim_ppc_spr778_regnum, sim_ppc_spr779_regnum,
    sim_ppc_spr780_regnum, sim_ppc_spr781_regnum,
    sim_ppc_spr782_regnum, sim_ppc_spr783_regnum,
    sim_ppc_spr784_regnum, sim_ppc_spr785_regnum,
    sim_ppc_spr786_regnum, sim_ppc_spr787_regnum,
    sim_ppc_spr788_regnum, sim_ppc_spr789_regnum,
    sim_ppc_spr790_regnum, sim_ppc_spr791_regnum,
    sim_ppc_spr792_regnum, sim_ppc_spr793_regnum,
    sim_ppc_spr794_regnum, sim_ppc_spr795_regnum,
    sim_ppc_spr796_regnum, sim_ppc_spr797_regnum,
    sim_ppc_spr798_regnum, sim_ppc_spr799_regnum,
    sim_ppc_spr800_regnum, sim_ppc_spr801_regnum,
    sim_ppc_spr802_regnum, sim_ppc_spr803_regnum,
    sim_ppc_spr804_regnum, sim_ppc_spr805_regnum,
    sim_ppc_spr806_regnum, sim_ppc_spr807_regnum,
    sim_ppc_spr808_regnum, sim_ppc_spr809_regnum,
    sim_ppc_spr810_regnum, sim_ppc_spr811_regnum,
    sim_ppc_spr812_regnum, sim_ppc_spr813_regnum,
    sim_ppc_spr814_regnum, sim_ppc_spr815_regnum,
    sim_ppc_spr816_regnum, sim_ppc_spr817_regnum,
    sim_ppc_spr818_regnum, sim_ppc_spr819_regnum,
    sim_ppc_spr820_regnum, sim_ppc_spr821_regnum,
    sim_ppc_spr822_regnum, sim_ppc_spr823_regnum,
    sim_ppc_spr824_regnum, sim_ppc_spr825_regnum,
    sim_ppc_spr826_regnum, sim_ppc_spr827_regnum,
    sim_ppc_spr828_regnum, sim_ppc_spr829_regnum,
    sim_ppc_spr830_regnum, sim_ppc_spr831_regnum,
    sim_ppc_spr832_regnum, sim_ppc_spr833_regnum,
    sim_ppc_spr834_regnum, sim_ppc_spr835_regnum,
    sim_ppc_spr836_regnum, sim_ppc_spr837_regnum,
    sim_ppc_spr838_regnum, sim_ppc_spr839_regnum,
    sim_ppc_spr840_regnum, sim_ppc_spr841_regnum,
    sim_ppc_spr842_regnum, sim_ppc_spr843_regnum,
    sim_ppc_spr844_regnum, sim_ppc_spr845_regnum,
    sim_ppc_spr846_regnum, sim_ppc_spr847_regnum,
    sim_ppc_spr848_regnum, sim_ppc_spr849_regnum,
    sim_ppc_spr850_regnum, sim_ppc_spr851_regnum,
    sim_ppc_spr852_regnum, sim_ppc_spr853_regnum,
    sim_ppc_spr854_regnum, sim_ppc_spr855_regnum,
    sim_ppc_spr856_regnum, sim_ppc_spr857_regnum,
    sim_ppc_spr858_regnum, sim_ppc_spr859_regnum,
    sim_ppc_spr860_regnum, sim_ppc_spr861_regnum,
    sim_ppc_spr862_regnum, sim_ppc_spr863_regnum,
    sim_ppc_spr864_regnum, sim_ppc_spr865_regnum,
    sim_ppc_spr866_regnum, sim_ppc_spr867_regnum,
    sim_ppc_spr868_regnum, sim_ppc_spr869_regnum,
    sim_ppc_spr870_regnum, sim_ppc_spr871_regnum,
    sim_ppc_spr872_regnum, sim_ppc_spr873_regnum,
    sim_ppc_spr874_regnum, sim_ppc_spr875_regnum,
    sim_ppc_spr876_regnum, sim_ppc_spr877_regnum,
    sim_ppc_spr878_regnum, sim_ppc_spr879_regnum,
    sim_ppc_spr880_regnum, sim_ppc_spr881_regnum,
    sim_ppc_spr882_regnum, sim_ppc_spr883_regnum,
    sim_ppc_spr884_regnum, sim_ppc_spr885_regnum,
    sim_ppc_spr886_regnum, sim_ppc_spr887_regnum,
    sim_ppc_spr888_regnum, sim_ppc_spr889_regnum,
    sim_ppc_spr890_regnum, sim_ppc_spr891_regnum,
    sim_ppc_spr892_regnum, sim_ppc_spr893_regnum,
    sim_ppc_spr894_regnum, sim_ppc_spr895_regnum,
    sim_ppc_spr896_regnum, sim_ppc_spr897_regnum,
    sim_ppc_spr898_regnum, sim_ppc_spr899_regnum,
    sim_ppc_spr900_regnum, sim_ppc_spr901_regnum,
    sim_ppc_spr902_regnum, sim_ppc_spr903_regnum,
    sim_ppc_spr904_regnum, sim_ppc_spr905_regnum,
    sim_ppc_spr906_regnum, sim_ppc_spr907_regnum,
    sim_ppc_spr908_regnum, sim_ppc_spr909_regnum,
    sim_ppc_spr910_regnum, sim_ppc_spr911_regnum,
    sim_ppc_spr912_regnum, sim_ppc_spr913_regnum,
    sim_ppc_spr914_regnum, sim_ppc_spr915_regnum,
    sim_ppc_spr916_regnum, sim_ppc_spr917_regnum,
    sim_ppc_spr918_regnum, sim_ppc_spr919_regnum,
    sim_ppc_spr920_regnum, sim_ppc_spr921_regnum,
    sim_ppc_spr922_regnum, sim_ppc_spr923_regnum,
    sim_ppc_spr924_regnum, sim_ppc_spr925_regnum,
    sim_ppc_spr926_regnum, sim_ppc_spr927_regnum,
    sim_ppc_spr928_regnum, sim_ppc_spr929_regnum,
    sim_ppc_spr930_regnum, sim_ppc_spr931_regnum,
    sim_ppc_spr932_regnum, sim_ppc_spr933_regnum,
    sim_ppc_spr934_regnum, sim_ppc_spr935_regnum,
    sim_ppc_spr936_regnum, sim_ppc_spr937_regnum,
    sim_ppc_spr938_regnum, sim_ppc_spr939_regnum,
    sim_ppc_spr940_regnum, sim_ppc_spr941_regnum,
    sim_ppc_spr942_regnum, sim_ppc_spr943_regnum,
    sim_ppc_spr944_regnum, sim_ppc_spr945_regnum,
    sim_ppc_spr946_regnum, sim_ppc_spr947_regnum,
    sim_ppc_spr948_regnum, sim_ppc_spr949_regnum,
    sim_ppc_spr950_regnum, sim_ppc_spr951_regnum,
    sim_ppc_spr952_regnum, sim_ppc_spr953_regnum,
    sim_ppc_spr954_regnum, sim_ppc_spr955_regnum,
    sim_ppc_spr956_regnum, sim_ppc_spr957_regnum,
    sim_ppc_spr958_regnum, sim_ppc_spr959_regnum,
    sim_ppc_spr960_regnum, sim_ppc_spr961_regnum,
    sim_ppc_spr962_regnum, sim_ppc_spr963_regnum,
    sim_ppc_spr964_regnum, sim_ppc_spr965_regnum,
    sim_ppc_spr966_regnum, sim_ppc_spr967_regnum,
    sim_ppc_spr968_regnum, sim_ppc_spr969_regnum,
    sim_ppc_spr970_regnum, sim_ppc_spr971_regnum,
    sim_ppc_spr972_regnum, sim_ppc_spr973_regnum,
    sim_ppc_spr974_regnum, sim_ppc_spr975_regnum,
    sim_ppc_spr976_regnum, sim_ppc_spr977_regnum,
    sim_ppc_spr978_regnum, sim_ppc_spr979_regnum,
    sim_ppc_spr980_regnum, sim_ppc_spr981_regnum,
    sim_ppc_spr982_regnum, sim_ppc_spr983_regnum,
    sim_ppc_spr984_regnum, sim_ppc_spr985_regnum,
    sim_ppc_spr986_regnum, sim_ppc_spr987_regnum,
    sim_ppc_spr988_regnum, sim_ppc_spr989_regnum,
    sim_ppc_spr990_regnum, sim_ppc_spr991_regnum,
    sim_ppc_spr992_regnum, sim_ppc_spr993_regnum,
    sim_ppc_spr994_regnum, sim_ppc_spr995_regnum,
    sim_ppc_spr996_regnum, sim_ppc_spr997_regnum,
    sim_ppc_spr998_regnum, sim_ppc_spr999_regnum,
    sim_ppc_spr1000_regnum, sim_ppc_spr1001_regnum,
    sim_ppc_spr1002_regnum, sim_ppc_spr1003_regnum,
    sim_ppc_spr1004_regnum, sim_ppc_spr1005_regnum,
    sim_ppc_spr1006_regnum, sim_ppc_spr1007_regnum,
    sim_ppc_spr1008_regnum, sim_ppc_spr1009_regnum,
    sim_ppc_spr1010_regnum, sim_ppc_spr1011_regnum,
    sim_ppc_spr1012_regnum, sim_ppc_spr1013_regnum,
    sim_ppc_spr1014_regnum, sim_ppc_spr1015_regnum,
    sim_ppc_spr1016_regnum, sim_ppc_spr1017_regnum,
    sim_ppc_spr1018_regnum, sim_ppc_spr1019_regnum,
    sim_ppc_spr1020_regnum, sim_ppc_spr1021_regnum,
    sim_ppc_spr1022_regnum, sim_ppc_spr1023_regnum
  };


/* Sizes of various register sets.  */
enum
  {
    sim_ppc_num_gprs = 32,
    sim_ppc_num_fprs = 32,
    sim_ppc_num_vrs = 32,
    sim_ppc_num_srs = 16,
    sim_ppc_num_sprs = 1024,
  };


/* Return the register name for the supplied SPR number if any, or
   NULL if none.  */
extern const char *sim_spr_register_name (int);

#ifdef __cplusplus
}
#endif

#endif /* SIM_PPC_H */
