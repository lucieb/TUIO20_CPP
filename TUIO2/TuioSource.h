/*
 TUIO2 C++ Library
 Copyright (c) 2009-2014 Martin Kaltenbrunner <martin@tuio.org>
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 3.0 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library.
 */

#ifndef INCLUDED_TUIOSOURCE_H
#define INCLUDED_TUIOSOURCE_H

namespace TUIO2 {
    
    /**
     * The TuioSource class encapsulates the meta data for the TUIO source attributes provided in /tuio2/frm.
     *
     * @author Martin Kaltenbrunner
     * @version 2.0.a0
     */
    
    class LIBDECL TuioSource {
        
    protected:
        /**
         * The ID of the TUIO source
         */
        int source_id;
        /**
         * The name of the TUIO source
         */
        std::string source_name;
        /**
         * The instance of the TUIO source
         */
        int source_instance;
        /**
         * The address of the TUIO source
         */
        std::string source_addr;
        /**
         * The encoded sensor dimension
         */
        int dimension;
        
    public:
        
        /**
         * Sets the ID, name and address of the TUIO source
         *
         * @param	src_name	the name of the TUIO source
         */
        TuioSource() {
            source_id = 0;
            source_name = "";
            source_instance = 0;
            source_addr = "localhost";
            dimension = 0;
        };
        
        /**
         * Sets the ID, name and address of the TUIO source
         *
         * @param	src_name	the name of the TUIO source
         */
        TuioSource(const char *src_name) {
            source_id = 0;
            source_name = std::string(src_name);
            source_instance = 0;
            source_addr = "localhost";
            dimension = 0;
        };
        
        /**
         * Sets the ID, name and address of the TUIO source
         *
         * @param	src_name	the name of the TUIO source
         * @param	src_inst	the instance of the TUIO source
         * @param	src_addr	the address of the TUIO source
         */
        TuioSource(const char *src_name, int src_inst, const char *src_addr) {
            source_id = 0;
            source_name = std::string(src_name);
            source_instance = src_inst;
            source_addr = std::string(src_addr);
        };
        
        /**
         * Sets the ID, name and address of the TUIO source
         *
         * @param	src_id		the ID of the TUIO source
         * @param	src_name	the name of the TUIO source
         * @param	src_inst	the instance of the TUIO source
         * @param	src_addr	the address of the TUIO source
         */
        TuioSource(int src_id, const char *src_name, int src_inst, const char *src_addr) {
            source_id = src_id;
            source_name = std::string(src_name);
            source_instance = src_inst;
            source_addr = std::string(src_addr);
        };
        
        ~TuioSource() {};
        
        void setSourceString(const char *src_string) {
            
            /*source->setSourceName(strtok((char*)src, "@"));
             char *addr = strtok(NULL, "@");
             
             if (addr!=NULL) source_addr = addr;
             else source_addr = (char*)"localhost";
             */
        }
        
        void setSourceString(int src_id, const char *src_string) {
            
            source_id = src_id;
            setSourceString(src_string);
        }
        
        const char* getSourceString() {
            
            return "";
        }
        
        /**
         * Returns the ID of the TUIO source
         */
        int getSourceID() { return source_id; }
        
        /**
         * Returns the name of the TUIO source
         */
        const char* getSourceName() { return source_name.c_str(); }
        
        /**
         * Returns the instance of the TUIO source
         */
        int getSourceInstance() { return source_instance; }
        
        /**
         * Returns the address of the TUIO source
         */
        const char* getSourceAddress() { return source_addr.c_str(); }
        
        /**
         * Encodes the sensor dimension
         * @param   w   the sensor width
         * @param   h   the sensor height
         */
        void setDimension(short w, short h) {
            dimension = w << 16 | h;
        }
      
        /**
         * Sets the encoded sensor dimension
         * @param   d   the sensor dimension
         */
        void setDimension(int d) {
            dimension = d;
        }
        
        /**
         * Returns the encoded sensor dimension
         * @return	the encoded sensor dimension
         */
        int getDimension() {
            return dimension;
        }
        
        /**
         * Returns the decoded sensor width
         * @return	the decoded sensor width
         */
        short getWidth() {
            short width = dimension >> 16;
            return width;
        }
        
        /**
         * Returns the decoded sensor height
         * @return	the decoded sensor height
         */
        short getHeight() {
            short height = dimension & 0x0000FFFF;
            return height;
        }
    };
}
#endif // INCLUDED_TUIOSOURCE_H