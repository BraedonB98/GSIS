#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Ground station integration software FM Test Code
# Author: Braedon Bellamy
# Generated: Thu Sep 17 20:54:52 2020
##################################################

from distutils.version import StrictVersion

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from PyQt5 import Qt
from PyQt5 import Qt, QtCore
from PyQt5.QtCore import QObject, pyqtSlot
from gnuradio import analog
from gnuradio import audio
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import filter
from gnuradio import gr
from gnuradio import qtgui
from gnuradio import uhd
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import sip
import sys
import time
from gnuradio import qtgui


class GSISFMTEST(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Ground station integration software FM Test Code")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Ground station integration software FM Test Code")
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

        self.settings = Qt.QSettings("GNU Radio", "GSISFMTEST")

        if StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
            self.restoreGeometry(self.settings.value("geometry").toByteArray())
        else:
            self.restoreGeometry(self.settings.value("geometry", type=QtCore.QByteArray))

        ##################################################
        # Variables
        ##################################################
        self.sat = sat = 98.5
        self.samp_rate = samp_rate = 4e6

        ##################################################
        # Blocks
        ##################################################
        self.settingsTab = Qt.QTabWidget()
        self.settingsTab_widget_0 = Qt.QWidget()
        self.settingsTab_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.settingsTab_widget_0)
        self.settingsTab_grid_layout_0 = Qt.QGridLayout()
        self.settingsTab_layout_0.addLayout(self.settingsTab_grid_layout_0)
        self.settingsTab.addTab(self.settingsTab_widget_0, 'Settings')
        self.top_layout.addWidget(self.settingsTab)
        self._sat_options = (98.5, 106.7, 97.9, 97.3, 105.9, )
        self._sat_labels = ('98.5', '106.7', '97.9', '97.3', '105.9', )
        self._sat_group_box = Qt.QGroupBox('Satellite')
        self._sat_box = Qt.QHBoxLayout()
        class variable_chooser_button_group(Qt.QButtonGroup):
            def __init__(self, parent=None):
                Qt.QButtonGroup.__init__(self, parent)
            @pyqtSlot(int)
            def updateButtonChecked(self, button_id):
                self.button(button_id).setChecked(True)
        self._sat_button_group = variable_chooser_button_group()
        self._sat_group_box.setLayout(self._sat_box)
        for i, label in enumerate(self._sat_labels):
        	radio_button = Qt.QRadioButton(label)
        	self._sat_box.addWidget(radio_button)
        	self._sat_button_group.addButton(radio_button, i)
        self._sat_callback = lambda i: Qt.QMetaObject.invokeMethod(self._sat_button_group, "updateButtonChecked", Qt.Q_ARG("int", self._sat_options.index(i)))
        self._sat_callback(self.sat)
        self._sat_button_group.buttonClicked[int].connect(
        	lambda i: self.set_sat(self._sat_options[i]))
        self.settingsTab_layout_0.addWidget(self._sat_group_box)
        self.uhd_usrp_source_0 = uhd.usrp_source(
        	",".join(("", "")),
        	uhd.stream_args(
        		cpu_format="fc32",
        		channels=range(1),
        	),
        )
        self.uhd_usrp_source_0.set_samp_rate(samp_rate)
        self.uhd_usrp_source_0.set_time_unknown_pps(uhd.time_spec())
        self.uhd_usrp_source_0.set_center_freq(sat*1e6, 0)
        self.uhd_usrp_source_0.set_gain(1, 0)
        self.uhd_usrp_source_0.set_bandwidth(300, 0)
        self.analog_wfm_rcv_0 = analog.wfm_rcv(
        	quad_rate=48e4,
        	audio_decimation=10,
        )
        self.WavSink = blocks.wavfile_sink('/home/braedonb98/GSIS/WXTOIMGFIles/GSISSatTest', 1, 48000, 8)
        self.WaterfallSink = qtgui.waterfall_sink_c(
        	1024, #size
        	firdes.WIN_BLACKMAN_hARRIS, #wintype
        	sat*1e6, #fc
        	samp_rate, #bw
        	"", #name
                1 #number of inputs
        )
        self.WaterfallSink.set_update_time(0.10)
        self.WaterfallSink.enable_grid(False)
        self.WaterfallSink.enable_axis_labels(True)

        if not True:
          self.WaterfallSink.disable_legend()

        if "complex" == "float" or "complex" == "msg_float":
          self.WaterfallSink.set_plot_pos_half(not True)

        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        colors = [0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        for i in xrange(1):
            if len(labels[i]) == 0:
                self.WaterfallSink.set_line_label(i, "Data {0}".format(i))
            else:
                self.WaterfallSink.set_line_label(i, labels[i])
            self.WaterfallSink.set_color_map(i, colors[i])
            self.WaterfallSink.set_line_alpha(i, alphas[i])

        self.WaterfallSink.set_intensity_range(-140, 10)

        self._WaterfallSink_win = sip.wrapinstance(self.WaterfallSink.pyqwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._WaterfallSink_win)
        self.Resampler = filter.rational_resampler_ccc(
                interpolation=1,
                decimation=8,
                taps=None,
                fractional_bw=None,
        )
        self.LowPassFilter = filter.fir_filter_ccf(1, firdes.low_pass(
        	1, samp_rate, 10e3, 2e6, firdes.WIN_HAMMING, 6.76))
        self.FreqSink = qtgui.freq_sink_c(
        	1024, #size
        	firdes.WIN_BLACKMAN_hARRIS, #wintype
        	sat*1e6, #fc
        	samp_rate, #bw
        	"", #name
        	1 #number of inputs
        )
        self.FreqSink.set_update_time(0.10)
        self.FreqSink.set_y_axis(-140, 10)
        self.FreqSink.set_y_label('Relative Gain', 'dB')
        self.FreqSink.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.FreqSink.enable_autoscale(False)
        self.FreqSink.enable_grid(False)
        self.FreqSink.set_fft_average(1.0)
        self.FreqSink.enable_axis_labels(True)
        self.FreqSink.enable_control_panel(False)

        if not True:
          self.FreqSink.disable_legend()

        if "complex" == "float" or "complex" == "msg_float":
          self.FreqSink.set_plot_pos_half(not True)

        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        for i in xrange(1):
            if len(labels[i]) == 0:
                self.FreqSink.set_line_label(i, "Data {0}".format(i))
            else:
                self.FreqSink.set_line_label(i, labels[i])
            self.FreqSink.set_line_width(i, widths[i])
            self.FreqSink.set_line_color(i, colors[i])
            self.FreqSink.set_line_alpha(i, alphas[i])

        self._FreqSink_win = sip.wrapinstance(self.FreqSink.pyqwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._FreqSink_win)
        self.DCBlocker = filter.dc_blocker_cc(1024, True)
        self.AudioSink = audio.sink(48000, '', True)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.DCBlocker, 0), (self.FreqSink, 0))
        self.connect((self.DCBlocker, 0), (self.Resampler, 0))
        self.connect((self.DCBlocker, 0), (self.WaterfallSink, 0))
        self.connect((self.LowPassFilter, 0), (self.analog_wfm_rcv_0, 0))
        self.connect((self.Resampler, 0), (self.LowPassFilter, 0))
        self.connect((self.analog_wfm_rcv_0, 0), (self.AudioSink, 0))
        self.connect((self.analog_wfm_rcv_0, 0), (self.WavSink, 0))
        self.connect((self.uhd_usrp_source_0, 0), (self.DCBlocker, 0))

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "GSISFMTEST")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_sat(self):
        return self.sat

    def set_sat(self, sat):
        self.sat = sat
        self._sat_callback(self.sat)
        self.uhd_usrp_source_0.set_center_freq(self.sat*1e6, 0)
        self.WaterfallSink.set_frequency_range(self.sat*1e6, self.samp_rate)
        self.FreqSink.set_frequency_range(self.sat*1e6, self.samp_rate)

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.uhd_usrp_source_0.set_samp_rate(self.samp_rate)
        self.WaterfallSink.set_frequency_range(self.sat*1e6, self.samp_rate)
        self.LowPassFilter.set_taps(firdes.low_pass(1, self.samp_rate, 10e3, 2e6, firdes.WIN_HAMMING, 6.76))
        self.FreqSink.set_frequency_range(self.sat*1e6, self.samp_rate)


def main(top_block_cls=GSISFMTEST, options=None):

    if StrictVersion("4.5.0") <= StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def quitting():
        tb.stop()
        tb.wait()
    qapp.aboutToQuit.connect(quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()
