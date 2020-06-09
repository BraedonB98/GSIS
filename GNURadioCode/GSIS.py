#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#
# SPDX-License-Identifier: GPL-3.0
#
# GNU Radio Python Flow Graph
# Title: Ground Station Integration Software
# Author: Braedon Bellamy
# GNU Radio version: 3.8.1.0

from distutils.version import StrictVersion

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print("Warning: failed to XInitThreads()")

from PyQt5 import Qt
from PyQt5.QtCore import QObject, pyqtSlot
from gnuradio import qtgui
from gnuradio.filter import firdes
import sip
from gnuradio import analog
from gnuradio import audio
from gnuradio import blocks
from gnuradio import filter
from gnuradio import gr
import sys
import signal
from argparse import ArgumentParser
from gnuradio.eng_arg import eng_float, intx
from gnuradio import eng_notation
from gnuradio.qtgui import Range, RangeWidget
import osmosdr
import time
from gnuradio import qtgui

class GSIS(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Ground Station Integration Software")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Ground Station Integration Software")
        qtgui.util.check_set_qss()
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
            pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "GSIS")

        try:
            if StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
                self.restoreGeometry(self.settings.value("geometry").toByteArray())
            else:
                self.restoreGeometry(self.settings.value("geometry"))
        except:
            pass

        ##################################################
        # Variables
        ##################################################
        self.sat = sat = 97.3
        self.samp_rate = samp_rate = 4e6
        self.freq = freq = 97.3e6

        ##################################################
        # Blocks
        ##################################################
        self.settingsTab = Qt.QTabWidget()
        self.settingsTab_widget_0 = Qt.QWidget()
        self.settingsTab_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.settingsTab_widget_0)
        self.settingsTab_grid_layout_0 = Qt.QGridLayout()
        self.settingsTab_layout_0.addLayout(self.settingsTab_grid_layout_0)
        self.settingsTab.addTab(self.settingsTab_widget_0, 'Settings')
        self.top_grid_layout.addWidget(self.settingsTab)
        # Create the options list
        self._sat_options = (97.3, 102.7, 106.7, )
        # Create the labels list
        self._sat_labels = ('NOAA-15', 'NOAA-18', 'NOAA-19', )
        # Create the combo box
        # Create the radio buttons
        self._sat_group_box = Qt.QGroupBox('Satellite' + ": ")
        self._sat_box = Qt.QHBoxLayout()
        class variable_chooser_button_group(Qt.QButtonGroup):
            def __init__(self, parent=None):
                Qt.QButtonGroup.__init__(self, parent)
            @pyqtSlot(int)
            def updateButtonChecked(self, button_id):
                self.button(button_id).setChecked(True)
        self._sat_button_group = variable_chooser_button_group()
        self._sat_group_box.setLayout(self._sat_box)
        for i, _label in enumerate(self._sat_labels):
            radio_button = Qt.QRadioButton(_label)
            self._sat_box.addWidget(radio_button)
            self._sat_button_group.addButton(radio_button, i)
        self._sat_callback = lambda i: Qt.QMetaObject.invokeMethod(self._sat_button_group, "updateButtonChecked", Qt.Q_ARG("int", self._sat_options.index(i)))
        self._sat_callback(self.sat)
        self._sat_button_group.buttonClicked[int].connect(
            lambda i: self.set_sat(self._sat_options[i]))
        self.settingsTab_layout_0.addWidget(self._sat_group_box)
        self.rational_resampler_xxx_1 = filter.rational_resampler_ccc(
                interpolation=1,
                decimation=8,
                taps=None,
                fractional_bw=None)
        self.rational_resampler_xxx_0 = filter.rational_resampler_ccc(
                interpolation=48,
                decimation=50,
                taps=None,
                fractional_bw=None)
        self.qtgui_waterfall_sink_x_0 = qtgui.waterfall_sink_c(
            1024, #size
            firdes.WIN_BLACKMAN_hARRIS, #wintype
            sat*1e6, #fc
            samp_rate, #bw
            "", #name
            1 #number of inputs
        )
        self.qtgui_waterfall_sink_x_0.set_update_time(0.10)
        self.qtgui_waterfall_sink_x_0.enable_grid(False)
        self.qtgui_waterfall_sink_x_0.enable_axis_labels(True)



        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        colors = [0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]

        for i in range(1):
            if len(labels[i]) == 0:
                self.qtgui_waterfall_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_waterfall_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_waterfall_sink_x_0.set_color_map(i, colors[i])
            self.qtgui_waterfall_sink_x_0.set_line_alpha(i, alphas[i])

        self.qtgui_waterfall_sink_x_0.set_intensity_range(-140, 10)

        self._qtgui_waterfall_sink_x_0_win = sip.wrapinstance(self.qtgui_waterfall_sink_x_0.pyqwidget(), Qt.QWidget)
        self.top_grid_layout.addWidget(self._qtgui_waterfall_sink_x_0_win)
        self.qtgui_freq_sink_x_0 = qtgui.freq_sink_c(
            1024, #size
            firdes.WIN_BLACKMAN_hARRIS, #wintype
            sat*1e6, #fc
            samp_rate, #bw
            "", #name
            1
        )
        self.qtgui_freq_sink_x_0.set_update_time(0.10)
        self.qtgui_freq_sink_x_0.set_y_axis(-140, 10)
        self.qtgui_freq_sink_x_0.set_y_label('Relative Gain', 'dB')
        self.qtgui_freq_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.qtgui_freq_sink_x_0.enable_autoscale(False)
        self.qtgui_freq_sink_x_0.enable_grid(False)
        self.qtgui_freq_sink_x_0.set_fft_average(1.0)
        self.qtgui_freq_sink_x_0.enable_axis_labels(True)
        self.qtgui_freq_sink_x_0.enable_control_panel(False)



        labels = ['', '', '', '', '',
            '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
            1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
            "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0]

        for i in range(1):
            if len(labels[i]) == 0:
                self.qtgui_freq_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_freq_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_freq_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_freq_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_freq_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_freq_sink_x_0_win = sip.wrapinstance(self.qtgui_freq_sink_x_0.pyqwidget(), Qt.QWidget)
        self.top_grid_layout.addWidget(self._qtgui_freq_sink_x_0_win)
        self.osmosdr_source_1 = osmosdr.source(
            args="numchan=" + str(1) + " " + ""
        )
        self.osmosdr_source_1.set_time_unknown_pps(osmosdr.time_spec_t())
        self.osmosdr_source_1.set_sample_rate(samp_rate)
        self.osmosdr_source_1.set_center_freq(sat*1e6, 0)
        self.osmosdr_source_1.set_freq_corr(0, 0)
        self.osmosdr_source_1.set_gain(8, 0)
        self.osmosdr_source_1.set_if_gain(20, 0)
        self.osmosdr_source_1.set_bb_gain(20, 0)
        self.osmosdr_source_1.set_antenna('', 0)
        self.osmosdr_source_1.set_bandwidth(100000, 0)
        self.low_pass_filter_0 = filter.fir_filter_ccf(
            1,
            firdes.low_pass(
                1,
                samp_rate,
                10e3,
                2e6,
                firdes.WIN_HAMMING,
                6.76))
        self._freq_range = Range(90e6, 110e6, 200e3, 97.3e6, 200)
        self._freq_win = RangeWidget(self._freq_range, self.set_freq, 'Frequency', "counter_slider", float)
        self.top_grid_layout.addWidget(self._freq_win)
        self.dc_blocker_xx_0 = filter.dc_blocker_cc(1024, True)
        self.blocks_wavfile_sink_0 = blocks.wavfile_sink('/home/braedonb98/Desktop/Wxtoimginput.wav', 1, 48000, 8)
        self.audio_sink_0 = audio.sink(48000, '', True)
        self.analog_wfm_rcv_0 = analog.wfm_rcv(
        	quad_rate=48e4,
        	audio_decimation=10,
        )



        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_wfm_rcv_0, 0), (self.audio_sink_0, 0))
        self.connect((self.analog_wfm_rcv_0, 0), (self.blocks_wavfile_sink_0, 0))
        self.connect((self.dc_blocker_xx_0, 0), (self.qtgui_freq_sink_x_0, 0))
        self.connect((self.dc_blocker_xx_0, 0), (self.qtgui_waterfall_sink_x_0, 0))
        self.connect((self.dc_blocker_xx_0, 0), (self.rational_resampler_xxx_1, 0))
        self.connect((self.low_pass_filter_0, 0), (self.rational_resampler_xxx_0, 0))
        self.connect((self.osmosdr_source_1, 0), (self.dc_blocker_xx_0, 0))
        self.connect((self.rational_resampler_xxx_0, 0), (self.analog_wfm_rcv_0, 0))
        self.connect((self.rational_resampler_xxx_1, 0), (self.low_pass_filter_0, 0))

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "GSIS")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_sat(self):
        return self.sat

    def set_sat(self, sat):
        self.sat = sat
        self._sat_callback(self.sat)
        self.osmosdr_source_1.set_center_freq(self.sat*1e6, 0)
        self.qtgui_freq_sink_x_0.set_frequency_range(self.sat*1e6, self.samp_rate)
        self.qtgui_waterfall_sink_x_0.set_frequency_range(self.sat*1e6, self.samp_rate)

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.low_pass_filter_0.set_taps(firdes.low_pass(1, self.samp_rate, 10e3, 2e6, firdes.WIN_HAMMING, 6.76))
        self.osmosdr_source_1.set_sample_rate(self.samp_rate)
        self.qtgui_freq_sink_x_0.set_frequency_range(self.sat*1e6, self.samp_rate)
        self.qtgui_waterfall_sink_x_0.set_frequency_range(self.sat*1e6, self.samp_rate)

    def get_freq(self):
        return self.freq

    def set_freq(self, freq):
        self.freq = freq



def main(top_block_cls=GSIS, options=None):

    if StrictVersion("4.5.0") <= StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def sig_handler(sig=None, frame=None):
        Qt.QApplication.quit()

    signal.signal(signal.SIGINT, sig_handler)
    signal.signal(signal.SIGTERM, sig_handler)

    timer = Qt.QTimer()
    timer.start(500)
    timer.timeout.connect(lambda: None)

    def quitting():
        tb.stop()
        tb.wait()
    qapp.aboutToQuit.connect(quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()
