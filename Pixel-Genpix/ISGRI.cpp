//____________________________________________________________________ 
// File: ISGRI.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-10 15:35:34+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "ISGRI.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#include "dal.h"
#include "dal3gen.h"

namespace Pix {
  ISGRI::ISGRI() try : m_process(0),
			 m_lowL(0.),
			 m_highL(0.),
			 m_lowB(0.),
			 m_highB(0.),
			 m_oversample(0) {
    std::cout << "[ISGRI]: New instance " << this << std::endl;    
  } catch( ... ) {
    std::cerr << "ISGRI: Construction failed in initialization." << std::endl;
  }
  
  ISGRI::~ISGRI() throw()
  {}
  
  void ISGRI::process(Process *proc) {
  }
  
  const Process * ISGRI::process() const {
  }
  
  void ISGRI::setup(const char * inIMG, const Image & ref, double lowL, double highL, double lowB, double highB, int oversample) {
    std::cout << "[ISGRI] setup : --- Reading input image " << inIMG << std::endl;

    std::vector<const char *> * m_imagetypes = new std::vector<const char *>;
    typedef std::vector<const char *>::const_iterator imgTypeIter;

    std::map<const char*,std::vector<dal_element*> * > m_image_indices;
    typedef std::map<const char*,std::vector<dal_element*> * >::iterator imgIdxIter;

    // Supported image tyoes:
    m_imagetypes->push_back("IMATYPE=='INTENSITY' || IMATYPE=='RECONSTRUCTED'");
    m_imagetypes->push_back("IMATYPE=='EXPOSURE'");
    m_imagetypes->push_back("IMATYPE=='VARIANCE'");
    
    int status = 0;
    int n_extensions = 3; // The number of extensions in the image file

    dal_element *img_idx = 0;
    dal_element *idx_extension = 0;
    
    char extension[DAL_MAX_ATTRIBUTE_SIZE];

    // Open the img file:
    status = DALobjectOpen(inIMG, &img_idx, status);
    status = DALattributeGet(img_idx, "IDXMEMBR", DAL_CHAR, &extension, 0, 0, status);

    // Create a map of extension name (i.e. image type) to vector of dal_element pointers.
    // The pointers will point to the child elements which point to FITS image data:
    for(imgTypeIter i = m_imagetypes->begin(); i != m_imagetypes->end(); ++i) {
      m_image_indices[*i] = new std::vector<dal_element*>;  
    }

    for (imgIdxIter i = m_image_indices.begin(); i !=  m_image_indices.end(); ++i) {
      std::cout << "[ISGRI] setup : --- Image type: " << (*i).first << std::endl;
      
      int n_img = 0;
      status = DAL3GENindexFindMember(img_idx, extension, (*i).first, 
				      &n_img, &idx_extension, status);
      
      // Now read all the images and get their indices. Store the indices so we can later read
      // the data pointed to by those indices (i.e. FITS image data):
      for (int j = 1; j <= n_img; j++) {
	dal_element *child_index = 0;
	fitsfile *fileptr = 0;
	
	status = DAL3GENindexGetMember(idx_extension, extension, j, &child_index, status);
	// Add the dal element pointer to our map:
	(*i).second->push_back(child_index);
	// Get the FITS file pointer:
	status = DALelementGetFilePtr(child_index, &fileptr, status);

	if (fileptr != 0) {
	  std::cout << "[ISGRI] setup : === Energy band ===" << std::endl;
	  
	  // Read the FITS image file:
	  double emin;
	  double emax;
	  
	  status = fits_read_key(fileptr,TDOUBLE,(char*)"E_MIN", &emin, NULL, &status);
	  status = fits_read_key(fileptr,TDOUBLE,(char*)"E_MAX", &emax, NULL, &status);
	  std::cout << "[ISGRI] setup : --- E_MIN = " << emin << std::endl;
	  std::cout << "[ISGRI] setup : --- E_MAX = " << emax << std::endl;






	  
	}
	// Store the data:
	
	// Close the child_index element once we actually store the extracted image data from the FITS file:
	status = DALobjectClose(child_index, DAL_SAVE, 0);
      }

      // Report number of images found:
      std::cout << "[ISGRI] setup : --- Got " << (*i).second->size() << " images for ext " << (*i).first << std::endl;
    }
    
    // Close image index:
    status = DALobjectClose(idx_extension, DAL_SAVE, 0);
    
    // Close the img file:
    status = DALobjectClose(img_idx, DAL_SAVE, 0);

    delete m_imagetypes;
  }
  
  void ISGRI::run_loop() {
  }
  
  void ISGRI::write() {
  }
  
  const std::string Pix::ISGRI::print() const {
    std::stringstream O(std::stringstream::out);
    O << "lowL         -- " << m_lowL        << "\n"; 
    O << "highL        -- " << m_highL       << "\n";
    O << "lowB         -- " << m_lowB        << "\n";
    O << "highB        -- " << m_highB       << "\n";
    O << "overSampling -- " << m_oversample  << "\n";
    return std::string(O.str());
  }
}

std::ostream & operator<< (std::ostream & O, const Pix::ISGRI & o) {
  O << o.print();
  return O;
}
