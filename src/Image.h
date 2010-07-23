// Image class:

#ifndef IMAGE_H
#define IMAGE_H

namespace PX {

	class Image {
		public:
			Image();
			virtual ~Image();

			static const char *HEADER;

		private:
			char m_instrument[20];
			int m_sizex;
			int m_sizey;
			double m_tstart;
			double m_telapse;
			double m_dexposure;
			char m_ctype1[20];
			char m_ctype2[20];
			double m_crpix1;
			double m_crval1;
			double m_crpix2;
			double m_crval2;
			double m_cd[4];
			double m_longpole;
			double m_latpole;
			double m_emin;
			double m_emax;
			struct WorldCoor *m_wcs;
			Image *outwcs;
			char m_imatype[20];
			float *m_data;
			float *m_variance;
			float *m_exposure;
			Image *m_next;
		};
}

#endif // IMAGE_H
